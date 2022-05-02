#include <stdio.h>
#include <tidy.h>
#include <tidybuffio.h>
#include <curl/curl.h>

/*
curl write callback, to fill tidy's input buffer...
*/
uint write_cb(char *in, uint size, uint nmemb, TidyBuffer *out)
{
    uint r;
    r = size * nmemb;
    tidyBufAppend(out, in, r);

    return r;
}

/* traverse the document tree */
void dump_node(TidyDoc doc, TidyNode tnod, int indent)
{
    TidyNode child;
    for(child = tidyGetChild(tnod); child; child = tidyGetNext(child))
    {
        ctmbstr name = tidyNodeGetName(child);
        if(name)
        {
            /* if it has a name, then it's an HTML tag */
            TidyAttr attr;
            printf("%*.*s%s ", indent, indent, "<", name);
            /* walk the attribute list */
            for(attr = tidyAttrFirst(child); attr; attr = tidyAttrNext(attr))
            {
                printf("%s", tidyAttrName(attr));
                tidyAttrValue(attr)?printf("=\"%s\" ", tidyAttrValue(attr)):printf(" ");
            }

            printf(">\n");
        }
        else
        {
            /* if no name, it's text or CDATA... */
            TidyBuffer buf;
            tidyBufInit(&buf);
            tidyNodeGetText(doc, child, &buf);
            printf("%*.*s\n", indent, indent, buf.bp?(char *)buf.bp:" ");
            tidyBufFree(&buf);
        }

        dump_node(doc, child, indent + 4); // recursive
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        CURL *curl;
        char curl_errbuf[CURL_ERROR_SIZE];
        TidyDoc tdoc;
        TidyBuffer docbuf = {0};
        TidyBuffer tidy_errbuf = {0};
        int err;

        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);

        tdoc = tidyCreate();
        tidyOptSetBool(tdoc, TidyForceOutput, yes);
        tidyOptSetInt(tdoc, TidyWrapLen, 4096);
        tidySetErrorBuffer(tdoc, &tidy_errbuf);
        tidyBufInit(&docbuf);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &docbuf);
        err = curl_easy_perform(curl);
        if(!err)
        {
            err = tidyParseBuffer(tdoc, &docbuf); // parse the input
            if(err >= 0)
            {
                err = tidyCleanAndRepair(tdoc); // fix any problems
                if(err >= 0)
                {
                    err = tidyRunDiagnostics(tdoc); // load tidy error buffer
                    if(err >= 0)
                    {
                        dump_node(tdoc, tidyGetRoot(tdoc), 0); // walk the tree
                        fprintf(stderr, "%s\n", tidy_errbuf.bp); // show errors
                    }
                }
            }
        }
        else 
        {
            fprintf(stderr, "%s\n", curl_errbuf);
        }

        // clean up
        curl_easy_cleanup(curl);
        tidyBufFree(&docbuf);
        tidyBufFree(&tidy_errbuf);
        tidyRelease(tdoc);

        return err;
    }
    else
    {
        printf("usage: %s <url>\n", argv[0]);
    }

    return 0;
}
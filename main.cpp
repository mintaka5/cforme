#include <iostream>
#include <openssl/sha.h>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

string sha256_simple(const string s)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, s.c_str(), s.size());
    SHA256_Final(hash, &ctx);

    stringstream ss;
    for(int i=0; i<SHA224_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int) hash[i];
    }

    return ss.str();
}

int main()
{
    cout << "Hello World" << endl;
    
    cout << sha256_simple("value is soul!") << endl;
    cout << sha256_simple("hi there") << endl;

    return 0;
}
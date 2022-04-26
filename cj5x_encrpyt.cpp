#include <iostream>
#include <string>

#include <cryptopp/eccrypto.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>

using namespace std;
using namespace CryptoPP;

void generate_signing_keys();

void generate_signing_keys()
{
    AutoSeededRandomPool prng;
    
    ECDSA<ECP, SHA1>::PrivateKey k1;
    k1.Initialize(prng, ASN1::secp256k1());

    const Integer &x1 = k1.GetPrivateExponent();
    cout << "PRIVKEY1: " << hex << x1 << endl;

    
}

int main(int argc, char *argv[])
{
    /*if(!argv[1])
    {
        printf("usage: mdtest <digestname>\n");
        return 1;
    }*/

    generate_signing_keys();

    return 0;
}
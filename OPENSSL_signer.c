//
//  OPENSSL_signer.c
//  App
//
//  Created by Jan Fabel on 14.07.22.
//

#include "OPENSSL_signer.h"
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>



unsigned char* signSSL(char* keyd,int keyd_length, char* input, int input_length) {

BIO *publicBIO = NULL;
EVP_PKEY *privateKey = NULL;

if (!(publicBIO = BIO_new_mem_buf(keyd,keyd_length))) {
    printf("BIO_new_mem_buf() failed!");
    return NULL;
}

if (!PEM_read_bio_PrivateKey(publicBIO, &privateKey, NULL, NULL)) {
    printf("PEM_read_bio_PrivateKey() failed!");
    return NULL;
}

const char * data = input;
unsigned int length = input_length;
int outlen;
unsigned char * outbuf[EVP_MAX_MD_SIZE];
const EVP_MD * digest = EVP_sha1();
//EVP_MD_CTX md_ctx;
    
EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();

    EVP_SignInit(md_ctx, digest);
EVP_SignUpdate(md_ctx, data, length);
if (EVP_SignFinal(md_ctx, (unsigned char*) outbuf, (unsigned int *) &outlen, privateKey)) {
    printf("Signed successfully.");
}
EVP_PKEY_free(privateKey);
    

return (unsigned char*) outbuf;
}

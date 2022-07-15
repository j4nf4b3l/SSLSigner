//
//  OPENSSL_signer.h
//  App
//
//  Created by Jan Fabel on 14.07.22.
//

#ifndef OPENSSL_signer_h
#define OPENSSL_signer_h

#include <stdio.h>
unsigned char* signSSL(char* keyd,int keyd_length, char* input, int input_length);

#endif /* OPENSSL_signer_h */

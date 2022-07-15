SRCDIR = CSources
SHAREDLIB = libOPENSSL_signer.so

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SHAREDLIBPATH = /usr/lib
endif
ifeq ($(UNAME_S),Darwin)
	SHAREDLIBPATH = /usr/local/lib
endif

Signer: $(SRCDIR)/OPENSSL_signer.c
	clang -shared $(SRCDIR)/OPENSSL_signer.c -lcrypto -o $(SHAREDLIB)
	cp libOPENSSL_signer.so $(SHAREDLIBPATH)

clean:
	-rm -f $(SHAREDLIB)
	-rm -f $(SHAREDLIBPATH)/$(SHAREDLIB)

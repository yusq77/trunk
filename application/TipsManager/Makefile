include ../../Makefile.DetermineARCH

CC=gcc
CFLAGS=-I../../include -g -Wall -Wno-pointer-sign

BIN= test

ifeq ($(ARCH),x64)
	LIBS=-L../../lib64 -lunionlog
else
	LIBS=-L../../lib -lunionlog
endif

all: $(BIN) 
test:main.c
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS) -Wl,-rpath=../../lib64/
		cp -f $@ ../../bin/
clean:
	rm -rf *.o $(BIN)

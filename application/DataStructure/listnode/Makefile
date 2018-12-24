include ../../../Makefile.DetermineARCH

CC=gcc
CFLAGS=-g -Wall -I../../../include

BIN= test

ifeq ($(ARCH),x64)
	LIBS=-L../../../lib64 -lunionlog
else
	LIBS=-L../../../lib -lunionlog
endif

all: $(BIN) 
test:listnode.c
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS) -Wl,-rpath=../../../lib64/
		cp -f $@ ../../../bin/
clean:
	rm -rf *.o $(BIN)

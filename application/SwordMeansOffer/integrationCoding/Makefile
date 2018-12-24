include ../../../Makefile.DetermineARCH

CC=g++ -std=gnu++0x #-Wno-write-strings
CFLAGS=-g -Wall -I../../../include

BIN= test

ifeq ($(ARCH),x64)
	LIBS=-L../../../lib64 -lunionlog
else
	LIBS=-L../../../lib -lunionlog
endif

all: $(BIN) 
test:04_FindInPartiallySortedMatrix.cpp
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS) -Wl,-rpath=../../../lib64/
		cp -f $@ ../../../bin/
clean:
	echo $(BIN);\
	rm -rf *.o $(BIN)

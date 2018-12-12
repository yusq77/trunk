include ../../Makefile.head
include ../../Makefile.DetermineARCH

CC=gcc
CFLAGS=-Wall -g -Wno-pointer-sign

INCLUDE=-I../../include
BINARY=logTest
LIBS=libunionlog.so
LIBPATH=../../lib64
LIBLD= -L../../lib64 -lunionlog

CMPLE_LIB_PATH = ../../lib
INSTALL_LIB_PATH = /usr/lib/
ifeq ($(ARCH),x64)
	CMPLE_LIB_PATH = ../../lib64/
	INSTALL_LIB_PATH = /usr/lib64/
else
	CMPLE_LIB_PATH = ../../lib/
	INSTALL_LIB_PATH = /usr/lib/
endif

.PHONY: all
all: $(BINARY) $(LIBS)

$(BINARY):unionlog.c
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE) $(LIBLD)

$(LIBS): unionlog.c
	$(CC) $(CFLAGS) -shared -fPIC -DCOMPILE_FOR_LIB -o $@ $^ $(INCLUDE)
	cp -f $@ $(CMPLE_LIB_PATH)

install:
	cp -f $(LIBS) $(INSTALL_LIB_PATH)

include ../../Makefile.tail

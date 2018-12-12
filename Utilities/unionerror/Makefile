include ../../Makefile.head

LIBBINARY = libunionerror.so
all: $(LIBBINARY)
INSTALL_LIB_PATH = /usr/lib64/
CMPLE_LIB_PATH = ../../lib64/

INCLUDE = -I../../include

$(LIBBINARY):unionerror.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^  $(INCLUDE)
	cp -f $(LIBBINARY) $(CMPLE_LIB_PATH)

install:
	cp -f $(LIBBINARY) $(INSTALL_LIB_PATH)

include ../../Makefile.tail

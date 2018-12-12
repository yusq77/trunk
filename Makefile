include Makefile.head
default:all

####
DIRS=Utilities\
	modules\
	application\
####

build: clean all 

####
include Makefile.tail

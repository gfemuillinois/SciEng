#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= test.C

TEMPLATE_INSTANCES = test_tinst.cc

SOURCE_FILES = 

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:    $(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

test: test.o test_tinst.o
	$(LINK) test.o test_tinst.o

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -f *.o
	rm -rf docs/ConcreteArrayShape
	rm -rf docs/ConcreteRigidArray1d
	rm -f core

#docs:
# doxygen .... TBD

# Depenedence list created with g++ -c -I.. -MM file.C

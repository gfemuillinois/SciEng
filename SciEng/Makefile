#
#
include ../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= tString.C tBool.C

TEMPLATE_INSTANCES = String_tinst.cc

SOURCE_FILES = String.C

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:    $(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tString: tString.o String.o String_tinst.o
	$(LINK) tString.o String.o String_tinst.o

tBool: tBool.o Boolean.o
	$(LINK) tBool.o Boolean.o

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -f *.o

# Depenedence list created with g++ -c -I.. -MM String.C

String.o: String.C ../SciEng/String.h ../SciEng/Subscript.h \
 ../SciEng/Fallible.h ../SciEng/Boolean.h ../SciEng/SciEngErr.h

tString.o: tString.C ../SciEng/String.h ../SciEng/Subscript.h \
 ../SciEng/Fallible.h ../SciEng/Boolean.h ../SciEng/SciEngErr.h

String_tinst.o: String_tinst.cc

Boolean.o: Boolean.C ../SciEng/Boolean.h 

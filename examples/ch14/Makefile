include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= exceptionLeak.C exceptionNoLeak.C tCounted.C tMolecule.C

TEMPLATE_INSTANCES = exceptionLeak_tinst.cc exceptionNoLeak_tinst.cc \
	tCounted_tinst.cc tMolecule_tinst.cc

SOURCE_FILES = CopiedObjPtrDemo.C badCall.C equiv-dcls.C  macro.C 

ALL_FILES =  $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

exceptionLeak: exceptionLeak.o exceptionLeak_tinst.o
	$(LINK)	exceptionLeak.o exceptionLeak_tinst.o $(SCIENGLIB)

exceptionNoLeak: exceptionNoLeak.o exceptionNoLeak_tinst.o
	$(LINK)	exceptionNoLeak.o exceptionNoLeak_tinst.o $(SCIENGLIB)

tCounted: tCounted.o tCounted_tinst.o
	$(LINK)	tCounted.o tCounted_tinst.o $(SCIENGLIB)

tMolecule: tMolecule.o tMolecule_tinst.o
	$(LINK)	tMolecule.o tMolecule_tinst.o $(SCIENGLIB)

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

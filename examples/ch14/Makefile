#
#
HOSTTYPE = $(shell uname)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= exceptionLeak.C exceptionNoLeak.C tCounted.C tMolecule.C

TEMPLATE_INSTANCES = exceptionLeak_tinst.cc exceptionNoLeak_tinst.cc \
	tCounted_tinst.cc tMolecule_tinst.cc

SOURCE_FILES = CopiedObjPtrDemo.C badCall.C equiv-dcls.C  macro.C 

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 
	    
# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
exceptionLeak: exceptionLeak.o exceptionLeak_tinst.o
	$(LINK)	exceptionLeak.o exceptionLeak_tinst.o $(SCIENGLIB)

# Executables built from more than one object go here:
exceptionNoLeak: exceptionNoLeak.o exceptionNoLeak_tinst.o
	$(LINK)	exceptionNoLeak.o exceptionNoLeak_tinst.o $(SCIENGLIB)

# Executables built from more than one object go here:
tCounted: tCounted.o tCounted_tinst.o
	$(LINK)	tCounted.o tCounted_tinst.o $(SCIENGLIB)

# Executables built from more than one object go here:
tMolecule: tMolecule.o tMolecule_tinst.o
	$(LINK)	tMolecule.o tMolecule_tinst.o $(SCIENGLIB)

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps

#-include Deps/empty.d
Deps/empty.d:
	test -d Deps || mkdir Deps
	touch $@

$(DEPENDLIST): Deps/empty.d

#Automatically generated dependencies for .C and .cc files
-include $(DEPENDLIST)

check:
	@echo HOSTTYPE: $(HOSTTYPE)
	@echo CXX,CC,LD: $(CXX) : $(CC) : $(LD)
	@echo OPT: $(OPT)
	@echo OPTM: $(OPTM)
	@echo ALL_FILES: $(ALL_FILES)
	@echo
	@echo OBJ_FILES: $(OBJ_FILES)
	@echo
	@echo DEPENDLIST: $(DEPENDLIST)

# The sequence of runs will stop if any executable 
# returns non-zero value.
run_all:
	@echo Running exceptionLeak: ;  exceptionLeak
	@echo Running exceptionNoLeak: ;  exceptionNoLeak
	@echo Running tCounted: ;  tCounted < input_for_tCounted
	@echo Running tMolecule: ;  tMolecule < input_for_tMolecule 



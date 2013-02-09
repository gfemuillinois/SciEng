#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= sizet.C tTuplize.C tArrayErr.C
#                  average.C


SOURCE_FILES = Array2d-with-dim.C ArrayErr.C ArraynT.C ArrayxD.C rigid.C \
               SciEngErr.C SciEngString.C

TEMPLATE_INSTANCES = tTuplize_tinst.cc
#                    average_tinst.cc

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
tTuplize: tTuplize.o tTuplize_tinst.o
	@echo Linking $@
	$(LINK) tTuplize.o tTuplize_tinst.o $(SCIENGLIB)

average: average.o average_tinst.o
	@echo Linking $@
	$(LINK) average.o average_tinst.o $(SCIENGLIB)

tArrayErr: tArrayErr.o  $(SCIENGLIB)
	@echo Linking $@
	$(LINK) tArrayErr.o $(SCIENGLIB)

#	$(LINK) tArrayErr.o ArrayErr.o ../../SciEng/SciEngErr.o ../../SciEng/SciEngString.o

SciEngString.C:
	ln -s ../../SciEng/SciEngString.C .

SciEngErr.C:
	ln -s ../../SciEng/SciEngErr.C .

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps
	rm -f SciEngString.C SciEngErr.C

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
#	@echo Running sizet: ;  sizet
	@echo Running tTuplize: ;   tTuplize
	@echo Running tArrayErr: ;  tArrayErr
#	@echo Running average: ;   average

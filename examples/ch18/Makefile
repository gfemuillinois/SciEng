#
#
HOSTTYPE = $(shell uname)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= blank-concat.C demoString.C miscdcls.C nrerror.C \
             syncIO.C tLegendreFit.C tRectSVDRep.C tXERBLA.C tempdel.C \

TEMPLATE_INSTANCES = tLegendreFit_tinst.cc tRectSVDRep_tinst.cc

SOURCE_FILES = 

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o)

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=) tXERBLA_FT.f

# Executables built from more than one object go here:
miscdcls:	miscdcls.o rand.o 
		@echo Linking $@
		$(LINK) miscdcls.o rand.o $(ALLLIBS)

nrerror:	nrerror.o nrfunction.o
		@echo Linking $@
		$(LINK) nrerror.o nrfunction.o $(SCIENGLIB)

tLegendreFit:	tLegendreFit.o tLegendreFit_tinst.o
		@echo Linking $@
		$(LINK) tLegendreFit.o tLegendreFit_tinst.o $(ALLLIBS)

tRectSVDRep:	tRectSVDRep.o  tRectSVDRep_tinst.o
		@echo Linking $@
		$(LINK) tRectSVDRep.o tRectSVDRep_tinst.o $(ALLLIBS)

tXERBLA:	tXERBLA.o
		@echo Linking $@
		$(LINK) tXERBLA.o $(ALLLIBS)

tXERBLA_FT:     tXERBLA_FT.o tXERBLA_FT.f
		@echo Linking $@
		g77 -o tXERBLA_FT  tXERBLA_FT.o -lblas

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps
	rm -f clarch.h

#-include Deps/empty.d
Deps/empty.d: clarch.h
	test -d Deps || mkdir Deps
	touch $@

$(DEPENDLIST): Deps/empty.d

clarch.h:
	ln -s ../../../util++_ut/util/clarch.h


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
	@echo Running tLegendreFit: ; tLegendreFit
	@echo !!! NOT Running tRectSVDRep: ";  tRectSVDRep" !!!

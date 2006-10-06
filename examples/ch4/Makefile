#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= linefit.C linefit2.C  \
	          intersect.C ptrselect.C \
	          interactive.C  interactive2.C \
	          quadratic.C \
		  distance.C distance2.C 
#                 sqr.C tCheckedSimpleArray.C

TEMPLATE_INSTANCES = SimpleArray_tinst.cc  sqr_tinst.cc  CheckedSimpleArray_tinst.cc

SOURCE_FILES = FixedArray.C Point.C Line.C  SimpleFloatArray.C
#              sqr_1.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 

# Targets:

all:    $(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
ptrselect:	ptrselect.o Point.o Line.o
		@echo Linking $@
		$(LINK) ptrselect.o Point.o Line.o

intersect:	intersect.o Point.o Line.o
		@echo Linking $@
		$(LINK) intersect.o Point.o Line.o

distance:	distance.o Point.o Line.o
		@echo Linking $@
		$(LINK) distance.o Point.o Line.o

distance2:	distance2.o Point.o Line.o
		@echo Linking $@
		$(LINK) distance2.o Point.o Line.o

linefit:	linefit.o SimpleFloatArray.o
		@echo Linking $@
		$(LINK) linefit.o SimpleFloatArray.o

linefit2:       linefit2.o SimpleArray_tinst.o
		@echo Linking $@
		$(LINK)  linefit2.o SimpleArray_tinst.o

sqr:		sqr.o sqr_tinst.o sqr_1.o
		@echo Linking $@
		$(LINK) sqr.o  sqr_tinst.o sqr_1.o $(COMPLEXLIB)

tCheckedSimpleArray: tCheckedSimpleArray.o CheckedSimpleArray_tinst.o
		@echo Linking $@
		$(LINK) tCheckedSimpleArray.o CheckedSimpleArray_tinst.o

#CheckedSimpleArray_tinst.o: CheckedSimpleArray.h CheckedSimpleArray.tdef

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
	@echo Running linefit: ;  linefit < input_for_linefit
	@echo Running linefit2: ;  linefit2  < input_for_linefit
#	@echo Running sqr: ;  sqr
	@echo Running intersect: ;  intersect
	@echo Running ptrselect: ;  ptrselect
	@echo Running interactive: ;  interactive < input_for_interactive
	@echo Running interactive2: ;  interactive2 < input_for_interactive2
#	@echo Running tCheckedSimpleArray: ;  tCheckedSimpleArray
	@echo Running quadratic: ; quadratic 
	@echo Running distance: ; distance < input_for_distance
	@echo Running distance2: ;  distance2 < input_for_distance


#
#
HOSTTYPE = $(shell uname)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= tConcreteRigidArray.C tConcreteFormedArray.C \
	IteratorFrobenius.C tConcreteMax.C tCollect.C tDiagonal.C \
	while.C timeConcreteArray.C timeConcreteRigidArray1D.C  \
	timeConcreteRigidArray2D.C

TEMPLATE_INSTANCES = tConcreteFormedArray_tinst.cc tConcreteRigidArray_tinst.cc \
	IteratorFrobenius_tinst.cc tConcreteMax_tinst.cc tCollect_tinst.cc \
	tDiagonal_tinst.cc timeConcreteArray_tinst.cc \
	timeConcreteRigidArray1D_tinst.cc  timeConcreteRigidArray2D_tinst.cc

SOURCE_FILES = bad-assign.C timer.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES =  $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
tConcreteRigidArray:   tConcreteRigidArray.o tConcreteRigidArray_tinst.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	  tConcreteRigidArray.o tConcreteRigidArray_tinst.o $(SCIENGMATXLIB)


tConcreteFormedArray: tConcreteFormedArray.o  tConcreteFormedArray_tinst.o \
		     $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	  tConcreteFormedArray.o tConcreteFormedArray_tinst.o $(SCIENGMATXLIB)

IteratorFrobenius: IteratorFrobenius.o  IteratorFrobenius_tinst.o $(SCIENGLIB)
	@echo Linking $@
	$(LINK)	  IteratorFrobenius.o IteratorFrobenius_tinst.o $(SCIENGLIB)

tConcreteMax: tConcreteMax.o  tConcreteMax_tinst.o $(SCIENGLIB)
	@echo Linking $@
	$(LINK)	  tConcreteMax.o tConcreteMax_tinst.o $(SCIENGLIB)

tCollect: tCollect.o  tCollect_tinst.o $(SCIENGLIB)
	@echo Linking $@
	$(LINK)	  tCollect.o tCollect_tinst.o $(SCIENGLIB)

tDiagonal: tDiagonal.o  tDiagonal_tinst.o $(SCIENGLIB)
	@echo Linking $@
	$(LINK)	  tDiagonal.o tDiagonal_tinst.o $(SCIENGLIB)


timeConcreteArray: timeConcreteArray.o timer.o timeConcreteArray_tinst.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeConcreteArray.o timer.o timeConcreteArray_tinst.o $(SCIENGMATXLIB)

timeConcreteRigidArray1D: timeConcreteRigidArray1D.o timer.o \
			  timeConcreteRigidArray1D_tinst.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeConcreteRigidArray1D.o timer.o \
	        timeConcreteRigidArray1D_tinst.o $(SCIENGMATXLIB)

timeConcreteRigidArray2D: timeConcreteRigidArray2D.o timer.o \
                         timeConcreteRigidArray2D_tinst.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeConcreteRigidArray2D.o timer.o \
                timeConcreteRigidArray2D_tinst.o $(SCIENGMATXLIB)

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
	@echo Running tConcreteFormedArray: ; tConcreteFormedArray
	@echo Running tConcreteRigidArray: ; tConcreteRigidArray
	@echo Running timeConcreteArray: ; timeConcreteArray
	@echo Running timeConcreteRigidArray1D: ; timeConcreteRigidArray1D
	@echo Running timeConcreteRigidArray2D: ; timeConcreteRigidArray2D


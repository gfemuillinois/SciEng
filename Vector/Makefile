#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check


FILES_WITH_MAIN	= timeRigidArithmetic1d.C timeFormedArithmetic1d.C \
	timeRigidArithmetic2d.C  timeFormedArithmetic2d.C

TEMPLATE_INSTANCES = timeRigidArithmetic1d_tinst.cc timeFormedArithmetic1d_tinst.cc \
        timeRigidArithmetic2d_tinst.cc  timeFormedArithmetic2d_tinst.cc

SOURCE_FILES =  timer.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES =  $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o)

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
timeRigidArithmetic1d : timeRigidArithmetic1d.o timeRigidArithmetic1d_tinst.o timer.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeRigidArithmetic1d.o timeRigidArithmetic1d_tinst.o timer.o $(SCIENGMATXLIB)

timeRigidArithmetic2d : timeRigidArithmetic2d.o timeRigidArithmetic2d_tinst.o timer.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeRigidArithmetic2d.o timeRigidArithmetic2d_tinst.o timer.o $(SCIENGMATXLIB)

timeFormedArithmetic1d : timeFormedArithmetic1d.o timeFormedArithmetic1d_tinst.o timer.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeFormedArithmetic1d.o timeFormedArithmetic1d_tinst.o timer.o $(SCIENGMATXLIB)

timeFormedArithmetic2d : timeFormedArithmetic2d.o timeFormedArithmetic2d_tinst.o timer.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	timeFormedArithmetic2d.o timeFormedArithmetic2d_tinst.o timer.o $(SCIENGMATXLIB)

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps
	rm -rf docs/Distributing
	rm -rf docs/FormedArithmetic
	rm -rf docs/RigidArithmetic
	rm -f core

#docs:
# doxygen .... TBD

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
	@echo Running timeRigidArithmetic1d: ; timeRigidArithmetic1d
	@echo Running timeRigidArithmetic2d: ; timeRigidArithmetic2d 
	@echo Running timeFormedArithmetic1d: ; timeFormedArithmetic1d;
	@echo Running timeFormedArithmetic2d: ; timeFormedArithmetic2d;

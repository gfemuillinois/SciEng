# NOTE: We could compile AtwoodsMachine only using
#  make USE_IMPLICITY_TEMPL=YES
#

HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	=  lin-frac.C tASGArray.C tGroupD3.C tIntMod5.C \
		   AtwoodsMachine.C
#		tSpaceVector.C 

TEMPLATE_INSTANCES = tASGArray_tinst.cc tGroupD3_tinst.cc tIntMod5_tinst.cc \
			 AtwoodsMachine_tinst.cc
#		tSpaceVector_tinst.cc

SOURCE_FILES = global-category-template.C global-function-template.C \
	       FormedPhysicalData.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
tASGArray: tASGArray.o tASGArray_tinst.o
	@echo Linking $@
	$(LINK) tASGArray.o tASGArray_tinst.o $(SCIENGLIB)

tGroupD3: tGroupD3.o tGroupD3_tinst.o
	@echo Linking $@
	$(LINK) tGroupD3.o tGroupD3_tinst.o $(SCIENGLIB)

tIntMod5: tIntMod5.o tIntMod5_tinst.o
	@echo Linking $@
	$(LINK) tIntMod5.o tIntMod5_tinst.o $(SCIENGLIB)

tSpaceVector: tSpaceVector.o tSpaceVector_tinst.o
	@echo Linking $@
	$(LINK) tSpaceVector.o tSpaceVector_tinst.o $(SCIENGLIB)

AtwoodsMachine: AtwoodsMachine.o AtwoodsMachine_tinst.o FormedPhysicalData.o
	@echo Linking $@
	$(LINK) AtwoodsMachine.o AtwoodsMachine_tinst.o FormedPhysicalData.o $(SCIENGLIB)

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps
	rm -f FormedPhysicalData.C

FormedPhysicalData.C:
	ln -s ../../DataModeling/FormedPhysicalData.C .

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
	@echo Running lin-frac: ; lin-frac
	@echo Running tASGArray: ;   tASGArray
	@echo Running tGroupD3: ;    tGroupD3
	@echo Running tIntMod5: ;    tIntMod5
#	@echo Running tSpaceVector: ;  tSpaceVector
	@echo Running AtwoodsMachine: ;  AtwoodsMachine

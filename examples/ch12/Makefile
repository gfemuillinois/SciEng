# could compile pure-virtual-called.C onl with WERROR=
#
HOSTTYPE = $(shell uname)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= not-equal.C pure-virtual-called.C sumsq.C tCheckedSimpleArray.C \
		tEquality.C tGPIBComponent.C tGPIBComponentTC.C tMatrix.C \
		tMixApplesOranges.C tObjtype.C tRefsNObjs.C tSum.C

SOURCE_FILES = conversion.C  tSubscriptArray.C  tTypeErrsEg.C

TEMPLATE_INSTANCES = not_equal_tinst.cc sumsq_tinst.cc tCheckedSimpleArray_tinst.cc \
		     tEquality_tinst.cc tMatrix_tinst.cc tObjtype_tinst.cc tSum_tinst.cc

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 
	    
# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
tGPIBComponent:	tGPIBComponent.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
                ../ch9/GPIBInstrument.o
	@echo Linking $@
	$(LINK) tGPIBComponent.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
		../ch9/GPIBInstrument.o

tGPIBComponentTC: tGPIBComponentTC.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
                 ../ch9/GPIBInstrument.o
	@echo Linking $@
	$(LINK) tGPIBComponentTC.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
		../ch9/GPIBInstrument.o

tRefsNObjs: tRefsNObjs.o ../ch9/VoltageSupply.o ../ch9/Acme130_VS.o
	@echo Linking $@
	$(LINK) tRefsNObjs.o ../ch9/VoltageSupply.o ../ch9/Acme130_VS.o

not-equal: not-equal.o not_equal_tinst.o
	@echo Linking $@
	$(LINK) not-equal.o not_equal_tinst.o  $(SCIENGLIB)

sumsq: sumsq.o sumsq_tinst.o
	@echo Linking $@
	$(LINK) sumsq.o sumsq_tinst.o  $(SCIENGLIB)

tCheckedSimpleArray: tCheckedSimpleArray.o tCheckedSimpleArray_tinst.o
	@echo Linking $@
	$(LINK) tCheckedSimpleArray.o tCheckedSimpleArray_tinst.o  $(SCIENGLIB)

tEquality: tEquality.o tEquality_tinst.o
	@echo Linking $@
	$(LINK)  tEquality.o tEquality_tinst.o  $(SCIENGLIB)

tMatrix: tMatrix.o tMatrix_tinst.o
	@echo Linking $@
	$(LINK)  tMatrix.o tMatrix_tinst.o  $(SCIENGLIB)

tObjtype: tObjtype.o tObjtype_tinst.o
	@echo Linking $@
	$(LINK)  tObjtype.o tObjtype_tinst.o  $(SCIENGLIB)

tSum: tSum.o tSum_tinst.o
	@echo Linking $@
	$(LINK)  tSum.o tSum_tinst.o  $(SCIENGLIB)

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
	@echo Running not-equal: ;  not-equal
#	@echo Running pure-virtual-called: ;  pure-virtual-called
	@echo Running sumsq: ;  sumsq < input_for_sumsq 
	@echo Running tCheckedSimpleArray: ;  tCheckedSimpleArray
	@echo Running tEquality: ;  tEquality
	@echo Running tGPIBComponent: ;  tGPIBComponent
	@echo Running tGPIBComponentTC: ;  tGPIBComponentTC
	@echo Running tMatrix: ;  tMatrix
	@echo Running tMixApplesOranges: ;  tMixApplesOranges
	@echo Running tObjtype: ;  tObjtype
	@echo Running tRefsNObjs: ; tRefsNObjs
	@echo Running tSum: ;  tSum

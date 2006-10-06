#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check


FILES_WITH_MAIN	= Newton.C Stirling.C array-reverse.C array-zero.C bitwise.C \
	break.C charArray.C charcomp.C commandLine.C const.C cosang.C \
	coulombUse.C coulombsLaw-onefile.C enum.C ex-ptrs.C ex-varsketch.C \
	ex-while.C fortran-compatible-io.C funcarg.C intercepts.C io.C \
	iodemo.C linefit.C mat3by3mult.C mat3by3mult2.C prepostfix.C \
	ptrArray.C ptrconst.C ptrs.C refs.C regurgitate.C scope.C sqrtTable.C \
	trivial.C typedef.C

ALL_FILES = Newton.C Stirling.C array-reverse.C array-zero.C bitwise.C \
	break.C charArray.C charcomp.C commandLine.C comments.C const.C \
	cosang.C coulombUse.C coulombsLaw-onefile.C coulombsLaw.C dotproto.C\
	 doubleSqr.C enum.C ex-ptrs.C ex-refs.C ex-varsketch.C ex-while.C \
	fortran-compatible-io.C funcarg.C includes.C intercepts.C io.C \
	iodemo.C linefit.C mat3by3mult.C mat3by3mult2.C prepostfix.C \
	ptrArray.C ptrconst.C ptrdclstyles.C ptrs.C refs.C regurgitate.C \
	scope.C simplecpp.C sqrtTable.C tempctrl.C trivial.C typedef.C \
	vertstyle.C coulombsLawDef.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(ALL_FILES:%.C=Deps/%.d)

# Targets:


all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

coulombUse:	coulombUse.o coulombsLawDef.o
		$(LINK) coulombUse.o coulombsLawDef.o

clean:
	rm -f $(ALL_FILES:.C=.o)

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
	@echo Running Newton: ;  Newton
#	@echo Running Stirling: ;  Stirling
	@echo Running array-reverse: ;  array-reverse
	@echo Running array-zero: ;  array-zero
	@echo Running bitwise: ;  bitwise
#	@echo Running break: ; break
	@echo Running charArray: ; charArray
	@echo Running charcomp: ; charcomp
	@echo Running commandLine: ; commandLine
	@echo Running const: ; const < input_for_const
	@echo Running cosang: ;  cosang < input_for_cosang
	@echo Running coulombUse: ; coulombUse
	@echo Running coulombsLaw-onefile: ;  coulombsLaw-onefile
	@echo Running enum: ;  enum
	@echo Running ex-ptrs: ;  ex-ptrs
	@echo Running ex-varsketch: ;  ex-varsketch
	@echo Running ex-while: ;  ex-while
	@echo Running fortran-compatible-io: ;  fortran-compatible-io
	@echo Running funcarg: ;   funcarg
	@echo Running intercepts: ;  intercepts < input_for_intercepts
	@echo Running io: ;  io
	@echo Running iodemo: ;  iodemo < input_for_iodemo
	@echo Running linefit: ; linefit < input_for_linefit
	@echo Running mat3by3mult: ;  mat3by3mult
	@echo Running mat3by3mult2: ; mat3by3mult2 
	@echo Running prepostfix: ;  prepostfix
	@echo Running ptrArray: ;  ptrArray
	@echo Running ptrconst: ;  ptrconst
	@echo Running ptrs: ;  ptrs
	@echo Running refs: ;  refs
	@echo Running regurgitate: ;  regurgitate < input_for_regurgitate
#	@echo Running scope: ;  scope
	@echo Running sqrtTable: ;  sqrtTable < input_for_sqrtTable
	@echo Running trivial: ;  trivial
	@echo Running typedef: ;  typedef

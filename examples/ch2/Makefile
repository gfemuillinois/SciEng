include ../../SciEng.mkdefs

FILES_WITH_MAIN	= Newton.C Stirling.C array-reverse.C array-zero.C bitwise.C break.C charArray.C charcomp.C commandLine.C const.C cosang.C coulombUse.C coulombsLaw-onefile.C enum.C ex-ptrs.C ex-varsketch.C ex-while.C fortran-compatible-io.C funcarg.C intercepts.C io.C iodemo.C linefit.C mat3by3mult.C mat3by3mult2.C prepostfix.C ptrArray.C ptrconst.C ptrs.C refs.C regurgitate.C scope.C sqrtTable.C trivial.C typedef.C

ALL_FILES = Newton.C Stirling.C array-reverse.C array-zero.C bitwise.C break.C charArray.C charcomp.C commandLine.C comments.C const.C cosang.C coulombUse.C coulombsLaw-onefile.C coulombsLaw.C dotproto.C doubleSqr.C enum.C ex-ptrs.C ex-refs.C ex-varsketch.C ex-while.C fortran-compatible-io.C funcarg.C includes.C intercepts.C io.C iodemo.C linefit.C mat3by3mult.C mat3by3mult2.C prepostfix.C ptrArray.C ptrconst.C ptrdclstyles.C ptrs.C refs.C regurgitate.C scope.C simplecpp.C sqrtTable.C tempctrl.C trivial.C typedef.C vertstyle.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)
coulombUse:	coulombUse.o coulombsLaw-onefile.o
		$(LINK) coulombUse.o coulombsLaw-onefile.o

include ../../SciEng.mkdefs

FILES_WITH_MAIN	= ptr-member.C tCachingFunction.C tFAMaker.C tFunction.C tLegendre.C tNormalDensityFunction.C tPtrSin.C tReduce.C tSharedMean.C tSimpleFunction.C tSimpleTrig.C

ALL_FILES = FAMaker.C Lexer.C ptr-member.C tCachingFunction.C tFAMaker.C tFunction.C tLegendre.C tNormalDensityFunction.C tPtrSin.C tReduce.C tSharedMean.C tSimpleFunction.C tSimpleTrig.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tReduce:	tReduce.o
		$(LINK) tReduce.o $(COMPLEXLIB)

tFAMaker:	tFAMaker.o
		$(LINK) tReduce.o FAMaker.o $(COMPLEXLIB)

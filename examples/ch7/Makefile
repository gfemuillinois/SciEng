include ../../SciEng.mkdefs

FILES_WITH_MAIN	= cache.C mixedNesting.C newDemo.C static-linkage.C tAutoException.C tAutoNesting.C tDynLifetime.C tStaticNesting.C zero.C

ALL_FILES = Dangle.C Rational.C Rational1.C RationalComplex.C TraceLifetime.C cache.C class-scope.C dangle.C mixedNesting.C newDemo.C resource-acq.C static-linkage.C tAutoException.C tAutoNesting.C tDynLifetime.C tStaticNesting.C zero.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

mixedNesting:	mixedNesting.o TraceLifetime.o
		$(LINK) mixedNesting.o TraceLifetime.o

tDynLifetime:	tDynLifetime.o TraceLifetime.o
		$(LINK) tDynLifetime.o TraceLifetime.o

tAutoException:	tAutoException.o TraceLifetime.o
		$(LINK) tAutoException.o TraceLifetime.o

tAutoNesting:	tAutoNesting.o TraceLifetime.o
		$(LINK) tAutoNesting.o TraceLifetime.o

tStaticNesting:	tStaticNesting.o TraceLifetime.o
		$(LINK) tStaticNesting.o TraceLifetime.o

zero:		zero.o
		$(LINK) zero.o $(COMPLEXLIB)

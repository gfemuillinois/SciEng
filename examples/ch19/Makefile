include ../../SciEng.mkdefs

FILES_WITH_MAIN	= tDampedSVD.C tNewtonRaphson.C tRall.C

ALL_FILES = tDampedSVD.C tNewtonRaphson.C tRall.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tDampedSVD:	tDampedSVD.o
		$(LINK) tDampedSVD.o $(LAPACKLIB) $(BLASLIB) $(FORTRANLIB)

tNewtonRaphson:	tNewtonRaphson.o
		$(LINK) tNewtonRaphson.o $(LAPACKLIB) $(BLASLIB) $(FORTRANLIB)

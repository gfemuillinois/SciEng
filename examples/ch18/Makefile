include ../../SciEng.mkdefs

FILES_WITH_MAIN	= blank-concat.C demoString.C miscdcls.C nrerror.C syncIO.C tLegendreFit.C tRectSVDRep.C tXERBLA.C tempdel.C

ALL_FILES = blank-concat.C demoString.C miscdcls.C nrerror.C syncIO.C tLegendreFit.C tRectSVDRep.C tXERBLA.C tempdel.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

miscdcls:	miscdcls.o rand.o
		$(LINK) miscdcls.o rand.o $(FORTRANLIB)

nrerror:	nrerror.o nrfunction.o
		$(LINK) nrerror.o nrfunction.o

tLegendreFit:	tLegendreFit.o
		$(LINK) tLegendreFit.o $(LAPACKLIB) $(BLASLIB) $(FORTRANLIB)

tRectSVDRep:	tRectSVDRep.o
		$(LINK) tRectSVDRep.o $(LAPACKLIB) $(BLASLIB) $(FORTRANLIB)

tXERBLA:	tXERBLA.o
		$(LINK) tXERBLA.o $(BLASLIB) $(FORTRANLIB)

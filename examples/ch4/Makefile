include ../../SciEng.mkdefs

FILES_WITH_MAIN	= distance.C distance2.C interactive.C interactive2.C intersect.C linefit.C linefit2.C ptrselect.C quadratic.C sqr.C tCheckedSimpleArray.C

ALL_FILES = FixedArray.C Line.C Nested.C Point.C Point0.C SimpleFloatArray.C cLine.C distance.C distance2.C interactive.C interactive2.C intersect.C linefit.C linefit2.C ptrselect.C quadratic.C sqr.C tCheckedSimpleArray.C tPoint.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

distance:	distance.o Point.o Line.o
		$(LINK) distance.o Point.o Line.o

distance2:	distance2.o Point.o Line.o
		$(LINK) distance.o Point.o Line.o

intersect:	intersect.o Point.o Line.o
		$(LINK) intersect.o Point.o Line.o

linefit:	linefit.o SimpleFloatArray.o
		$(LINK) linefit.o SimpleFloatArray.o

ptrselect:	ptrselect.o Point.o Line.o
		$(LINK) ptrselect.o Point.o Line.o

sqr:		sqr.o
		$(LINK) sqr.o $(COMPLEXLIB)

#
#
include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= linefit.C linefit2.C  \
	          sqr.C  intersect.C ptrselect.C \
	          interactive.C  interactive2.C \
	          tCheckedSimpleArray.C quadratic.C \
		  distance.C distance2.C 

TEMPLATE_INSTANCES = SimpleArray_tinst.cc  sqr_tinst.cc  CheckedSimpleArray_tinst.cc

SOURCE_FILES = FixedArray.C Point.C Line.C sqr_1.C SimpleFloatArray.C

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:    $(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

ptrselect:	ptrselect.o Point.o Line.o
		$(LINK) ptrselect.o Point.o Line.o

intersect:	intersect.o Point.o Line.o
		$(LINK) intersect.o Point.o Line.o

distance:	distance.o Point.o Line.o
		$(LINK) distance.o Point.o Line.o

distance2:	distance2.o Point.o Line.o
		$(LINK) distance2.o Point.o Line.o

linefit:	linefit.o SimpleFloatArray.o
		$(LINK) linefit.o SimpleFloatArray.o

linefit2:       linefit2.o SimpleArray_tinst.o
		$(LINK)  linefit2.o SimpleArray_tinst.o

sqr:		sqr.o sqr_tinst.o sqr_1.o
		$(LINK) sqr.o  sqr_tinst.o sqr_1.o $(COMPLEXLIB)

tCheckedSimpleArray: tCheckedSimpleArray.o CheckedSimpleArray_tinst.o
		$(LINK) tCheckedSimpleArray.o CheckedSimpleArray_tinst.o

CheckedSimpleArray_tinst.o: CheckedSimpleArray.h CheckedSimpleArray.tdef

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

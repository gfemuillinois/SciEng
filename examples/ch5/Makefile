#
#
include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= abs.C abstemp.C args.C arrayArg.C con-callbr.C expdev.C resolve.C \
		 swap.C taxpy.C taxpy1.C wrong2.C

TEMPLATE_INSTANCES =  taxpy_tinst.cc taxpy1_tinst.cc  abs_tinst.cc args_tinst.cc \
		resolve_tinst.cc

SOURCE_FILES = blastemp.C dcldef.C dot.C hasVal.C logof.C  retdcl.C wrong1.C

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)


all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

taxpy1:	taxpy1.o  taxpy1_tinst.o $(SCIENGLIB)
	$(LINK) taxpy1.o  taxpy1_tinst.o $(COMPLEXLIB) $(SCIENGLIB)

taxpy: 	taxpy.o  taxpy_tinst.o $(SCIENGLIB)
	$(LINK) taxpy.o  taxpy_tinst.o $(COMPLEXLIB) $(SCIENGLIB)

abs:	abs.o abs_tinst.o
	$(LINK) abs.o abs_tinst.o -lstdc++

args: args.o args_tinst.o
	$(LINK) args.o args_tinst.o $(SCIENGLIB)

resolve: resolve.o resolve_tinst.o
	$(LINK) resolve.o resolve_tinst.o

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

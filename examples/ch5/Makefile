include ../../SciEng.mkdefs

FILES_WITH_MAIN	= abs.C abstemp.C args.C arrayArg.C con-callbr.C expdev.C resolve.C swap.C taxpy.C taxpy1.C wrong2.C

ALL_FILES = abs.C abstemp.C args.C arrayArg.C blastemp.C con-callbr.C dcldef.C dot.C expdev.C hasVal.C logof.C resolve.C retdcl.C swap.C taxpy.C taxpy1.C wrong1.C wrong2.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

abs:	abs.o
	$(LINK) abs.o $(COMPLEXLIB)

taxpy1:	taxpy1.o
	$(LINK) taxpy1.o $(COMPLEXLIB)

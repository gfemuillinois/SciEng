include ../../SciEng.mkdefs

FILES_WITH_MAIN	= taxpy.C taxpy1.C 

TEMPLATE_INSTANCES = axpy_tinst.cc Vector_tinst.cc

SOURCE_FILES =

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)


all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

taxpy1:	taxpy1.o
	$(LINK) taxpy1.o $(COMPLEXLIB)

taxpy: 	taxpy.o axpy_tinst.o Vector_tinst.o
	$(LINK) taxpy.o axpy_tinst.o Vector_tinst.o $(COMPLEXLIB)

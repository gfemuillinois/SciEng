include ../../SciEng.mkdefs

FILES_WITH_MAIN	= Driver.C tmpl1.C

ALL_FILES = Driver.C tmpl0.C tmpl1.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

Driver:	Driver.o
	$(LINK) Driver.o $(LAPACKLIB) $(BLASLIB) $(FORTRANLIB)

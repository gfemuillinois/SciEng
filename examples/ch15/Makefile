include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= Driver.C tmpl1.C

TEMPLATE_INSTANCES = Driver_tinst.cc tmpl1_tinst.cc

SOURCE_FILES =  tmpl0.C 

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)


all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

Driver:	Driver.o Driver_tinst.o
	$(LINK) Driver.o  Driver_tinst.o $(ALLLIBS)

tmpl1:	tmpl1.o tmpl1_tinst.o
	$(LINK) tmpl1.o  tmpl1_tinst.o $(ALLLIBS)


clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

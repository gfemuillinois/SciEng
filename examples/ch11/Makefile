include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= sizet.C tTuplize.C tArrayErr.C average.C


SOURCE_FILES = Array2d-with-dim.C ArrayErr.C ArraynT.C ArrayxD.C rigid.C \
               ../../SciEng/SciEngErr.C ../../SciEng/String.C

TEMPLATE_INSTANCES = tTuplize_tinst.cc average_tinst.cc

ALL_FILES =  $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tTuplize: tTuplize.o tTuplize_tinst.o
	$(LINK) tTuplize.o tTuplize_tinst.o $(SCIENGLIB)

average: average.o average_tinst.o
	$(LINK) average.o average_tinst.o $(SCIENGLIB)

tArrayErr: tArrayErr.o  $(SCIENGLIB)
	$(LINK) tArrayErr.o $(SCIENGLIB)

#	$(LINK) tArrayErr.o ArrayErr.o ../../SciEng/SciEngErr.o ../../SciEng/String.o


clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= solution1.C solution2.C  solution3.C

TEMPLATE_INSTANCES = solution1_tinst.cc solution2_tinst.cc solution3_tinst.cc

SOURCE_FILES = Element.C Element3.C

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)


all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

solution1: solution1.o solution1_tinst.o
	$(LINK) solution1.o solution1_tinst.o

solution2: solution2.o Element.o solution2_tinst.o
	$(LINK) solution2.o Element.o solution2_tinst.o

solution3: solution3.o Element3.o solution3_tinst.o
	$(LINK) solution3.o Element3.o solution3_tinst.o


clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

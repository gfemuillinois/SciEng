# NOTE: We could compile AtwoodsMachine only using
#  make USE_IMPLICITY_TEMPL=YES
#

include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	=  lin-frac.C tASGArray.C tGroupD3.C tIntMod5.C \
		   tSpaceVector.C AtwoodsMachine.C

TEMPLATE_INSTANCES = tASGArray_tinst.cc tGroupD3_tinst.cc tIntMod5_tinst.cc \
			tSpaceVector_tinst.cc AtwoodsMachine_tinst.cc

SOURCE_FILES = global-category-template.C global-function-template.C \
	       ../../DataModeling/FormedPhysicalData.C

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)


all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tASGArray: tASGArray.o tASGArray_tinst.o
	$(LINK) tASGArray.o tASGArray_tinst.o $(SCIENGLIB)

tGroupD3: tGroupD3.o tGroupD3_tinst.o
	$(LINK) tGroupD3.o tGroupD3_tinst.o $(SCIENGLIB)

tIntMod5: tIntMod5.o tIntMod5_tinst.o
	$(LINK) tIntMod5.o tIntMod5_tinst.o $(SCIENGLIB)

tSpaceVector: tSpaceVector.o tSpaceVector_tinst.o
	$(LINK) tSpaceVector.o tSpaceVector_tinst.o $(SCIENGLIB)

AtwoodsMachine: AtwoodsMachine.o AtwoodsMachine_tinst.o ../../DataModeling/FormedPhysicalData.o
	$(LINK) AtwoodsMachine.o AtwoodsMachine_tinst.o ../../DataModeling/FormedPhysicalData.o $(SCIENGLIB)

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

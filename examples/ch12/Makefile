include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= not-equal.C pure-virtual-called.C sumsq.C tCheckedSimpleArray.C \
		tEquality.C tGPIBComponent.C tGPIBComponentTC.C tMatrix.C \
		tMixApplesOranges.C tObjtype.C tRefsNObjs.C tSum.C

SOURCE_FILES = conversion.C  tSubscriptArray.C  tTypeErrsEg.C

TEMPLATE_INSTANCES = not_equal_tinst.cc sumsq_tinst.cc tCheckedSimpleArray_tinst.cc \
		     tEquality_tinst.cc tMatrix_tinst.cc tObjtype_tinst.cc tSum_tinst.cc

ALL_FILES =  $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tGPIBComponent:	tGPIBComponent.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
                ../ch9/GPIBInstrument.o
	$(LINK) tGPIBComponent.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
		../ch9/GPIBInstrument.o

tGPIBComponentTC: tGPIBComponentTC.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
                 ../ch9/GPIBInstrument.o
	$(LINK) tGPIBComponentTC.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o \
		../ch9/GPIBInstrument.o

tRefsNObjs: tRefsNObjs.o ../ch9/VoltageSupply.o ../ch9/Acme130_VS.o
	$(LINK) tRefsNObjs.o ../ch9/VoltageSupply.o ../ch9/Acme130_VS.o

not-equal: not-equal.o not_equal_tinst.o
	$(LINK) not-equal.o not_equal_tinst.o  $(SCIENGLIB)

sumsq: sumsq.o sumsq_tinst.o
	$(LINK) sumsq.o sumsq_tinst.o  $(SCIENGLIB)

tCheckedSimpleArray: tCheckedSimpleArray.o tCheckedSimpleArray_tinst.o
	$(LINK) tCheckedSimpleArray.o tCheckedSimpleArray_tinst.o  $(SCIENGLIB)

tEquality: tEquality.o tEquality_tinst.o
	$(LINK)  tEquality.o tEquality_tinst.o  $(SCIENGLIB)

tMatrix: tMatrix.o tMatrix_tinst.o
	$(LINK)  tMatrix.o tMatrix_tinst.o  $(SCIENGLIB)

tObjtype: tObjtype.o tObjtype_tinst.o
	$(LINK)  tObjtype.o tObjtype_tinst.o  $(SCIENGLIB)

tSum: tSum.o tSum_tinst.o
	$(LINK)  tSum.o tSum_tinst.o  $(SCIENGLIB)

clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)

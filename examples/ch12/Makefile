include ../../SciEng.mkdefs

FILES_WITH_MAIN	= not-equal.C pure-virtual-called.C sumsq.C tCheckedSimpleArray.C tEquality.C tGPIBComponent.C tGPIBComponentTC.C tMatrix.C tMixApplesOranges.C tObjtype.C tRefsNObjs.C tSum.C

ALL_FILES = conversion.C not-equal.C pure-virtual-called.C sumsq.C tCheckedSimpleArray.C tEquality.C tGPIBComponent.C tGPIBComponentTC.C tMatrix.C tMixApplesOranges.C tObjtype.C tRefsNObjs.C tSubscriptArray.C tSum.C tTypeErrsEg.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tGPIBComponent:		tGPIBComponent.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o ../ch9/GPIBInstrument.o
			$(LINK) tGPIBComponent.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o 	\
				../ch9/GPIBInstrument.o

tGPIBComponentTC:	tGPIBComponentTC.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o ../ch9/GPIBInstrument.o
			$(LINK) tGPIBComponentTC.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o 	\
				../ch9/GPIBInstrument.o

tRefsNObjs:		tRefsNObjs.o ../ch9/VoltageSupply.o ../ch9/Acme130_VS.o
			$(LINK) tRefsNObjs.o ../ch9/VoltageSupply.o ../ch9/Acme130_VS.o

include ../../SciEng.mkdefs

FILES_WITH_MAIN	= tAcme130_Acs.C tAcme130_GIData.C tAcme140.C tAcme230.C tCheckedFloatArray.C

ALL_FILES = Acme130_Acs.C Acme130_Fwd.C Acme130_GIData.C Acme130_VS_GI.C Acme130_VS_GI_GC.C Acme230.C GPIBInstrumentData.C GPIBInstrumentData_GI.C VoltOn59_VS_GI.C VoltyMetrics_VM_GI.C tAcme130_Acs.C tAcme130_GIData.C tAcme140.C tAcme230.C tCheckedFloatArray.C tNoV.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

tAcme130_Acs:		tAcme130_Acs.o ../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o GPIBInstrumentData_GI.o	\
				Acme130_Acs.o ../ch9/GPIBController.o
			$(LINK) tAcme130_Acs.o ../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o 	\
				GPIBInstrumentData_GI.o	Acme130_Acs.o ../ch9/GPIBController.o

tAcme130_GIData:	tAcme130_GIData.o ../ch9/GPIBController.o Acme130_GIData.o GPIBInstrumentData_GI.o	\
				../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o
			$(LINK) tAcme130_GIData.o ../ch9/GPIBController.o Acme130_GIData.o 	\
				GPIBInstrumentData_GI.o	../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o

tAcme140:		tAcme140.o ../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o	\
				Acme130_VS_GI_GC.o
			$(LINK) tAcme140.o ../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o 	\
				../ch9/GPIBController.o	Acme130_VS_GI_GC.o

tAcme230:		tAcme230.o Acme230.o VoltyMetrics_VM_GI.o Acme130_GIData.o GPIBInstrumentData_GI.o	\
				../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o ../ch9/GPIBController.o		\
				../ch9/Voltmeter.o
			$(LINK) tAcme230.o Acme230.o VoltyMetrics_VM_GI.o Acme130_GIData.o 	\
				GPIBInstrumentData_GI.o	../ch9/GPIBInstrument.o ../ch9/VoltageSupply.o 	\
				../ch9/GPIBController.o	../ch9/Voltmeter.o

tCheckedFloatArray:	tCheckedFloatArray.o ../ch6/SimpleFloatArray.o
			$(LINK) tCheckedFloatArray.o ../ch6/SimpleFloatArray.o

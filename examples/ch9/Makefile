include ../../SciEng.mkdefs

FILES_WITH_MAIN	= SeeCommonality.C SeeVoltageSupply.C tGPIBInstrument.C tIVTester.C tSimulator.C

ALL_FILES = Acme130Simulation.C Acme130_VS.C Acme130_VS_GI.C Acme130_VS_GI_GC.C ExperimentSimulation.C GPIBController.C GPIBController_GIS.C GPIBInstrument.C GPIBInstrumentSimulation.C IVTester.C SeeCommonality.C SeeVoltageSupply.C SimulatorFactory.C VoltageSupply.C Voltmeter.C VoltyMetricsSimulation.C VoltyMetrics_VM_GI.C new-virt-ret.C tGPIBInstrument.C tIVTester.C tSimulator.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

SeeVoltageSupply:	SeeVoltageSupply.o VoltageSupply.o Acme130_VS.o
			$(LINK) SeeVoltageSupply.o VoltageSupply.o Acme130_VS.o

tGPIBInstrument:	tGPIBInstrument.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 		\
				GPIBController.o GPIBInstrument.o Voltmeter.o VoltageSupply.o
			$(LINK) tGPIBInstrument.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 	\
				GPIBController.o GPIBInstrument.o Voltmeter.o VoltageSupply.o

tIVTester:		tIVTester.o VoltyMetrics_VM_GI.o GPIBController.o Acme130_VS_GI_GC.o	\
				VoltageSupply.o IVTester.o GPIBInstrument.o Voltmeter.o
			$(LINK) tIVTester.o VoltyMetrics_VM_GI.o GPIBController.o 		\
				Acme130_VS_GI_GC.o VoltageSupply.o IVTester.o GPIBInstrument.o	\
				Voltmeter.o

tSimulator:		tSimulator.o Acme130Simulation.o VoltyMetricsSimulation.o IVTester.o	\
				VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o GPIBController_GIS.o	\
				VoltageSupply.o GPIBInstrument.o Voltmeter.o SimulatorFactory.o	\
				ExperimentSimulation.o GPIBController.o GPIBInstrumentSimulation.o
			$(LINK) tSimulator.o Acme130Simulation.o VoltyMetricsSimulation.o	\
				IVTester.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 		\
				GPIBController_GIS.o VoltageSupply.o GPIBInstrument.o 		\
				Voltmeter.o SimulatorFactory.o ExperimentSimulation.o 		\
				GPIBController.o GPIBInstrumentSimulation.o

include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= SeeCommonality.C SeeVoltageSupply.C tGPIBInstrument.C tIVTester.C tSimulator.C

TEMPLATE_INSTANCES = tSimulator_tinst.cc

SOURCE_FILES = Acme130Simulation.C Acme130_VS.C Acme130_VS_GI.C Acme130_VS_GI_GC.C \
               ExperimentSimulation.C GPIBController.C GPIBController_GIS.C GPIBInstrument.C \
               GPIBInstrumentSimulation.C IVTester.C   \
               SimulatorFactory.C VoltageSupply.C Voltmeter.C VoltyMetricsSimulation.C \
               VoltyMetrics_VM_GI.C new-virt-ret.C 

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

SeeVoltageSupply:	SeeVoltageSupply.o VoltageSupply.o Acme130_VS.o
			$(LINK) SeeVoltageSupply.o VoltageSupply.o Acme130_VS.o $(SCIENGLIB)

tGPIBInstrument:	tGPIBInstrument.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 		\
				GPIBController.o GPIBInstrument.o Voltmeter.o VoltageSupply.o
			$(LINK) tGPIBInstrument.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 	\
				GPIBController.o GPIBInstrument.o Voltmeter.o VoltageSupply.o   \
				$(SCIENGLIB)

tIVTester:		tIVTester.o VoltyMetrics_VM_GI.o GPIBController.o Acme130_VS_GI_GC.o	\
				VoltageSupply.o IVTester.o GPIBInstrument.o Voltmeter.o
			$(LINK) tIVTester.o VoltyMetrics_VM_GI.o GPIBController.o 		\
				Acme130_VS_GI_GC.o VoltageSupply.o IVTester.o GPIBInstrument.o	\
				Voltmeter.o $(SCIENGLIB)

tSimulator:		tSimulator.o Acme130Simulation.o VoltyMetricsSimulation.o IVTester.o	\
				VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o GPIBController_GIS.o	\
				VoltageSupply.o GPIBInstrument.o Voltmeter.o SimulatorFactory.o	\
				ExperimentSimulation.o GPIBController.o GPIBInstrumentSimulation.o \
				tSimulator_tinst.o
			$(LINK) tSimulator.o Acme130Simulation.o VoltyMetricsSimulation.o	\
				IVTester.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 		\
				GPIBController_GIS.o VoltageSupply.o GPIBInstrument.o 		\
				Voltmeter.o SimulatorFactory.o ExperimentSimulation.o 		\
				GPIBController.o GPIBInstrumentSimulation.o tSimulator_tinst.o  \
				$(SCIENGLIB) $(SCIENGLIB)


clean:
	rm -f $(FILES_WITH_MAIN:.C=.o) \
	      $(TEMPLATE_INSTANCES:.cc=.o) \
	      $(SOURCE_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)


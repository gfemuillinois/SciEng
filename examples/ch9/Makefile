#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= SeeCommonality.C SeeVoltageSupply.C tGPIBInstrument.C \
                  tIVTester.C tSimulator.C

TEMPLATE_INSTANCES = tSimulator_tinst.cc

SOURCE_FILES = Acme130Simulation.C Acme130_VS.C Acme130_VS_GI.C Acme130_VS_GI_GC.C \
               ExperimentSimulation.C GPIBController.C GPIBController_GIS.C GPIBInstrument.C \
               GPIBInstrumentSimulation.C IVTester.C   \
               SimulatorFactory.C VoltageSupply.C Voltmeter.C VoltyMetricsSimulation.C \
               VoltyMetrics_VM_GI.C new-virt-ret.C 

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 
	    
# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
SeeVoltageSupply:	SeeVoltageSupply.o VoltageSupply.o Acme130_VS.o
			@echo Linking $@
			$(LINK) SeeVoltageSupply.o VoltageSupply.o Acme130_VS.o $(SCIENGLIB)

tGPIBInstrument:	tGPIBInstrument.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 		\
				GPIBController.o GPIBInstrument.o Voltmeter.o VoltageSupply.o
			@echo Linking $@	
			$(LINK) tGPIBInstrument.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 	\
				GPIBController.o GPIBInstrument.o Voltmeter.o VoltageSupply.o   \
				$(SCIENGLIB)

tIVTester:		tIVTester.o VoltyMetrics_VM_GI.o GPIBController.o Acme130_VS_GI_GC.o	\
				VoltageSupply.o IVTester.o GPIBInstrument.o Voltmeter.o
			@echo Linking $@
			$(LINK) tIVTester.o VoltyMetrics_VM_GI.o GPIBController.o 		\
				Acme130_VS_GI_GC.o VoltageSupply.o IVTester.o GPIBInstrument.o	\
				Voltmeter.o $(SCIENGLIB)

tSimulator:		tSimulator.o Acme130Simulation.o VoltyMetricsSimulation.o IVTester.o	\
				VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o GPIBController_GIS.o	\
				VoltageSupply.o GPIBInstrument.o Voltmeter.o SimulatorFactory.o	\
				ExperimentSimulation.o GPIBController.o GPIBInstrumentSimulation.o \
				tSimulator_tinst.o
			@echo Linking $@
			$(LINK) tSimulator.o Acme130Simulation.o VoltyMetricsSimulation.o	\
				IVTester.o VoltyMetrics_VM_GI.o Acme130_VS_GI_GC.o 		\
				GPIBController_GIS.o VoltageSupply.o GPIBInstrument.o 		\
				Voltmeter.o SimulatorFactory.o ExperimentSimulation.o 		\
				GPIBController.o GPIBInstrumentSimulation.o tSimulator_tinst.o  \
				$(SCIENGLIB) $(SCIENGLIB)


clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps

#-include Deps/empty.d
Deps/empty.d:
	test -d Deps || mkdir Deps
	touch $@

$(DEPENDLIST): Deps/empty.d

#Automatically generated dependencies for .C and .cc files
-include $(DEPENDLIST)

check:
	@echo HOSTTYPE: $(HOSTTYPE)
	@echo CXX,CC,LD: $(CXX) : $(CC) : $(LD)
	@echo OPT: $(OPT)
	@echo OPTM: $(OPTM)
	@echo ALL_FILES: $(ALL_FILES)
	@echo
	@echo OBJ_FILES: $(OBJ_FILES)
	@echo
	@echo DEPENDLIST: $(DEPENDLIST)

# The sequence of runs will stop if any executable 
# returns non-zero value.
run_all:
	@echo Running SeeCommonality: ;  SeeCommonality  < input_for_tests
	@echo Running SeeVoltageSupply: ;  SeeVoltageSupply  < input_for_tests
	@echo Running tGPIBInstrument: ;  tGPIBInstrument  < input_for_tests
	@echo Running tIVTester: ;  tIVTester  < input_for_tests
	@echo Running tSimulator: ;  tSimulator


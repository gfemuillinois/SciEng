/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <string.h>

#include "examples/ch9/GPIBController_GIS.h"
#include "examples/ch9/GPIBInstrumentSimulation.h"
#include "examples/ch9/SimulatorFactory.h"
             

GPIBController_GIS::GPIBController_GIS(const SimulatorFactory& factory) : 
    simulator_factory(factory),
    simulators(31) {
    simulators = 0;
}



void GPIBController_GIS::insert(const char* device_name, unsigned int address) { 
    simulators[address] = simulator_factory.create(device_name, the_experiment);
}



void GPIBController_GIS::send(unsigned int address, const char* msg) { 
    GPIBInstrumentSimulation* ip = simulators[address];
    if (ip != 0) ip -> send(msg);
    else throw "No simulator at specified GPIB address";
}

void GPIBController_GIS::send(unsigned int address, float f) { 
    GPIBInstrumentSimulation* ip = simulators[address];
    if (ip != 0) ip -> send(f);
    else throw "No simulator at specified GPIB address";
}

float GPIBController_GIS::receive(unsigned int address) { 
    float val;
    GPIBInstrumentSimulation* ip = simulators[address];
    if (ip != 0) val = ip -> receive();
    else throw "No simulator at specified GPIB address";
    return val;
}



GPIBController_GIS::~GPIBController_GIS() {
    for (int i = 0; i < simulators.numElts(); i++) {
        delete simulators[i];
    }
}


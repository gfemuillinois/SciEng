/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

#include "examples/ch9/CheckedSimpleArray.h"
#include "examples/ch9/GPIBController.h"
#include "examples/ch9/ExperimentSimulation.h"
class GPIBInstrumentSimulation;
class SimulatorFactory;
                   

class GPIBController_GIS : 
    public GPIBController {
public:
    GPIBController_GIS(const SimulatorFactory& factory);
    virtual ~GPIBController_GIS();

// GPIBController interface

    virtual void  insert(const char* device_name, unsigned int address);
    virtual void  send(unsigned int address, const char* buf);
    virtual void  send(unsigned int address, float f);
    virtual float receive(unsigned int address);

private:
    const SimulatorFactory& simulator_factory;
    CheckedSimpleArray<GPIBInstrumentSimulation*> simulators;
    ExperimentSimulation the_experiment;
};





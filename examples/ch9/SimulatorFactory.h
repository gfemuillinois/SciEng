/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SimulatorFactoryH
#define SimulatorFactoryH

#include "examples/ch9/GPIBInstrumentSimulation.h"
class ExperimentSimulation;


class SimulatorFactory {
public:
    virtual GPIBInstrumentSimulation* 
        create(const char* device_name, ExperimentSimulation& exp) const = 0;
    virtual ~SimulatorFactory();
};

#endif

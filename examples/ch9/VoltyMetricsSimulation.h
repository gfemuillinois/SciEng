/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/GPIBInstrumentSimulation.h"
#include "examples/ch9/ExperimentSimulation.h"


class VoltyMetricsSimulation :  
    public GPIBInstrumentSimulation {
public:
    VoltyMetricsSimulation(ExperimentSimulation& e);

    virtual void  send(const char*);
    virtual void  send(float f);
    virtual float receive();

private:
    ExperimentSimulation& the_experiment;
};


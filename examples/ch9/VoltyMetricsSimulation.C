/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/VoltyMetricsSimulation.h"

VoltyMetricsSimulation::VoltyMetricsSimulation(ExperimentSimulation& e) :
  the_experiment(e) {
}
void VoltyMetricsSimulation::send(const char*){
}

void VoltyMetricsSimulation::send(float){
}

#include <string.h>

float VoltyMetricsSimulation::receive() { 
    return the_experiment.test();
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Acme130Simulation.h"
#include "examples/ch9/ExperimentSimulation.h"

Acme130Simulation::Acme130Simulation(ExperimentSimulation& e) :
  the_experiment(e) {
}
void Acme130Simulation::send(const char*){
}

#include <string.h>

void Acme130Simulation::send(float f) { 
    the_experiment.apply(f);
}


float Acme130Simulation::receive() {
  return 0.0;
}

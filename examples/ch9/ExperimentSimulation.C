/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/ExperimentSimulation.h"

void ExperimentSimulation::apply(double voltage) {
  the_voltage = voltage;
}

double ExperimentSimulation::test() {
  return the_voltage;
}

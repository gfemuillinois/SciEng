/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/VoltyMetrics_VM_GI.h"


float VoltyMetrics_VM_GI::read() {       
    return my_controller.receive(my_gpib_address);
}


// Not shown.
VoltyMetrics_VM_GI::VoltyMetrics_VM_GI(GPIBController& controller, int what_address) :
  my_controller(controller),
  my_gpib_address(what_address) {
  my_controller.insert("VoltyMetrics_VM_GI", my_gpib_address);
}


void VoltyMetrics_VM_GI::send(float value){ 
    my_controller.send(my_gpib_address, value);
}


void VoltyMetrics_VM_GI::send(const char* cmd){ 
    my_controller.send(my_gpib_address, cmd);
}



float VoltyMetrics_VM_GI::receive() { 
    return my_controller.receive(my_gpib_address);
}




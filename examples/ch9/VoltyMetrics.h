/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/GPIBController_Stub.h"

class VoltyMetrics { 
public:
    VoltyMetrics(GPIBController_Stub& controller, int what_address);
    float read();
    // Other member functions go here.
private:
    GPIBController_Stub my_controller;
    int my_gpib_address;
};


float VoltyMetrics::read() {       
    return my_controller.receive(my_gpib_address);
}


// Not shown.
VoltyMetrics::VoltyMetrics(GPIBController_Stub& controller, int what_address) :
  my_controller(controller),
  my_gpib_address(what_address) {
  my_controller.insert("VoltyMetrics", my_gpib_address);
}



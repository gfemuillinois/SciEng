/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Acme130_VS.h"

void Acme130_VS::set(float volts) { 
    my_controller.send(my_gpib_address, volts);
}

float Acme130_VS::minimum() const { return 0.0; }
float Acme130_VS::maximum() const { return 10.0; }


Acme130_VS::Acme130_VS(GPIBController_Stub& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("Acme130_VS", gpib_address);
}



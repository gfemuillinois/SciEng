/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Acme130_VS_GI.h"

float Acme130_VS_GI::minimum() const { return 0.0; }
float Acme130_VS_GI::maximum() const { return 10.0; }


Acme130_VS_GI::Acme130_VS_GI(GPIBController_Stub& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("Acme130_VS_GI", gpib_address);
}



void Acme130_VS_GI::set(float voltage){ 
    if (voltage > maximum() || voltage < minimum()) throw "Acme 130 voltage out of range";
    send(voltage);
}



void Acme130_VS_GI::send(float value){ 
    my_controller.send(my_gpib_address, value);
}


void Acme130_VS_GI::send(const char* cmd){ 
    my_controller.send(my_gpib_address, cmd);
}



float Acme130_VS_GI::receive() { 
    return my_controller.receive(my_gpib_address);
}



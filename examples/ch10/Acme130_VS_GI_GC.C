/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Acme130_VS_GI_GC.h"

float Acme130_VS_GI_GC::minimum() const { return 0.0; }
float Acme130_VS_GI_GC::maximum() const { return 10.0; }


Acme130_VS_GI_GC::Acme130_VS_GI_GC(GPIBController& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("Acme130_VS_GI_GC", gpib_address);
}



void Acme130_VS_GI_GC::set(float voltage){ 
    if (voltage > maximum() || voltage < minimum()) throw "Acme 130 voltage out of range";
    send(voltage);
}



void Acme130_VS_GI_GC::send(float value){ 
    my_controller.send(my_gpib_address, value);
}


void Acme130_VS_GI_GC::send(const char* cmd){ 
    my_controller.send(my_gpib_address, cmd);
}



float Acme130_VS_GI_GC::receive() { 
    return my_controller.receive(my_gpib_address);
}



/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/VoltOn59_VS_GI.h"

float VoltOn59_VS_GI::minimum() const { return 0.0; }
float VoltOn59_VS_GI::maximum() const { return 10.0; }


VoltOn59_VS_GI::VoltOn59_VS_GI(GPIBController& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("VoltOn59_VS_GI", gpib_address);
}



void VoltOn59_VS_GI::set(float voltage){ 
    if (voltage > maximum() || voltage < minimum()) throw "VoltOn 59 voltage out of range";
    send(voltage);
}



void VoltOn59_VS_GI::send(float value){ 
    my_controller.send(my_gpib_address, value);
}


void VoltOn59_VS_GI::send(const char* cmd){ 
    my_controller.send(my_gpib_address, cmd);
}



float VoltOn59_VS_GI::receive() { 
    return my_controller.receive(my_gpib_address);
}




/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/GPIBInstrumentData_GI.h"

GPIBInstrumentData_GI::
GPIBInstrumentData_GI(GPIBController& c, int address, const char* name) :
    my_controller(c),
    my_gpib_address(address) {
    my_controller.insert(name, my_gpib_address);
}


void GPIBInstrumentData_GI::send(float value) { 
    my_controller.send(my_gpib_address, value);
}

void GPIBInstrumentData_GI::send(const char* cmd) { 
    my_controller.send(my_gpib_address, cmd);
}

float GPIBInstrumentData_GI::receive() { 
    return my_controller.receive(my_gpib_address);
}



/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/Acme130_Acs.h"


Acme130_Acs::Acme130_Acs(GPIBController& controller, int gpib_address) : 
    GPIBInstrumentData_GI(controller, gpib_address, "Acme130_Acs") {
}



void Acme130_Acs::set(float voltage){ 
    if (voltage > maximum() || voltage < minimum()) throw "Acme 130 voltage out of range";
    send(voltage);
}


float Acme130_Acs::minimum() const { return 0.0; }
float Acme130_Acs::maximum() const { return 10.0; }

                      

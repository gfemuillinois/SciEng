/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/Acme230.h"


float Acme230::maximum() const {     
    if (range_setting == high) return 100.0;
    return 10.0;
}


void Acme230::set(Range r) {       
    GPIBInstrument& gpibinst = *this;
    range_setting = r;
    if (range_setting == high) {       
        gpibinst.send("RNG1");
    } else {
        gpibinst.send("RNG0");
    }
}


void Acme230::set(float voltage) {       
    Acme130_GIData::set(voltage);
}


Acme230::Acme230(GPIBController& which_GPIB, int what_address) :
  Acme130_GIData(which_GPIB, what_address) {
}

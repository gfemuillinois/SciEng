/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Voltmeter.h"

float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float tst_voltage) {
    // Relative error at specified test voltage.
    supply.set(tst_voltage);
    return abs(tst_voltage - meter.read()) /  tst_voltage;
}



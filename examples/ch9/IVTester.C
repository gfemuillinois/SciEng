/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/IVTester.h"

IVTester::IVTester(VoltageSupply& vs, Voltmeter& vm) : 
    the_voltage_supply(vs),
    the_voltmeter(vm) {
}

                      

double IVTester::current(double voltage) { 
    the_voltage_supply.set(voltage);
    return the_voltmeter.read();
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/VoltageSupply.h"
#include "examples/ch9/Voltmeter.h"



class IVTester {               
public:
    IVTester(VoltageSupply& vs, Voltmeter& vm);
    double current(double voltage);
private:
    VoltageSupply& the_voltage_supply;
    Voltmeter& the_voltmeter;
};



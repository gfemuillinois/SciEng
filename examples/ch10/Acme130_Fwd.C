/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/Acme130_Fwd.h"

float Acme130_Fwd::minimum() const { return 0.0; }
float Acme130_Fwd::maximum() const { return 10.0; }

void Acme130_Fwd::set(float voltage) { 
    if (voltage > maximum() || voltage < minimum()) throw "Acme130 voltage out of range";
    send(voltage);
}


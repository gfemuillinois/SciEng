/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch7/class-scope.h"



const double c = 3.00e8;         // Speed of light
const double G = 6.67e-11;       // Gravitational constant
const double k = 1.38e-23;       // Boltzmann's constant
// ...





const double PhysicalConstants::c = 3.00e8;         // Speed of light
const double PhysicalConstants::G = 6.67e-11;       // Gravitational constant
const double PhysicalConstants::k = 1.38e-23;       // Boltzmann's constant
// ...



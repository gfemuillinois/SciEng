/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
void func() {
{

float f = 3.1;
double d = f;

}
{

float f = 3.1;
const double& dr = f;

}
{

float f = 3.1;
const double temp = f;
const double& d = temp;

}
}

#include <complex.h>

typedef complex ComplexDouble;

class ComplexFloat {
public:
    ComplexFloat(float, float);
    operator ComplexDouble();
    // ...
};


void g() {

ComplexFloat f(1.0, 2.0);
ComplexDouble dr = f;

}

void gr() {

ComplexFloat f(1.0, 2.0);
const ComplexDouble& dr = f;

}

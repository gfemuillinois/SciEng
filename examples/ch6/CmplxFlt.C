/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>


class ComplexFloat {
public:
    ComplexFloat(float r, float i);  // Construct from real & imaginary parts
    static ComplexFloat fromFile(istream& input = cin);
    // ...
};



ComplexFloat ComplexFloat::fromFile(istream& input) {
    float r;  input >> r;
    float i;  input >> i;
    return ComplexFloat(r, i);
}



ComplexFloat c = ComplexFloat::fromFile();



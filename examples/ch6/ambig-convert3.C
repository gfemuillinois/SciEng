/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class ComplexFloat;
class ComplexDouble;

class ComplexInt {
public:
    // ...
    ComplexDouble toComplexDouble() const;
};

class ComplexFloat {
public:
    // ...
    ComplexFloat(ComplexInt);
    // ...
};

class ComplexDouble {
public:
    ComplexDouble(ComplexFloat);
    // ...
};


extern float  arg(ComplexFloat z);    // Principal value of the argument of z
extern double arg(ComplexDouble z);   // Principal value of the argument of z


static void f() {
ComplexInt ci;
// ...

float a  = arg(ci);
double b = arg( ci.toComplexDouble() );


}


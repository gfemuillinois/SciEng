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
};

class ComplexFloat {
public:
    // ...
    ComplexFloat(ComplexInt);
    // ...
};

class ComplexDouble {
public:
    ComplexDouble(ComplexInt);
    ComplexDouble(ComplexFloat);
    // ...
};


extern float  arg(ComplexFloat z);    // Principal value of the argument of z
extern double arg(ComplexDouble z);   // Principal value of the argument of z




inline float arg(ComplexInt z) { return arg( ComplexFloat(z) ); }


static void f() {

ComplexInt ci;
// ...
double a = arg(ci); // WRONG: call matches arg(ComplexFloat) and arg(ComplexDouble)


double b = arg( ComplexDouble(ci) );

}


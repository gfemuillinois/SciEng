/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch7/Rational.h"
Rational::Rational(int numerator, int denominator) {
    int x = numerator;
    int y = denominator;
    // ...
}


const Rational Rational::zero(0, 1);
const Rational Rational::quarter(1, 4);
const Rational Rational::half(1, 2);


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch7/Rational1.h"


RationalInitializer::RationalInitializer() {
    if (count++ == 0) {
        Rational::zero = Rational(0, 1);
        Rational::quarter = Rational(1, 4);
        Rational::half = Rational(1, 2);
    }
}

int RationalInitializer::count = 0;


Rational::Rational() {
    // Default initializer leaves number undefined
}

Rational::Rational(int numerator, int denominator) {
    int x = numerator; 
    int y = denominator;
    // ...
}

Rational Rational::zero; // Runs default initializer
Rational Rational::quarter;
Rational Rational::half;

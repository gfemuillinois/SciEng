/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch7/Rational.h"
#include "examples/ch7/RationalComplex.h"

const RationalComplex RationalComplex::realHalf(Rational::half, Rational::zero);
const RationalComplex RationalComplex::imagHalf(Rational::zero, Rational::half);


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NumericalLimitsH
#define NumericalLimitsH

template<class T>
class NumericalLimits {
public:

    static const T   minimum;            // Minimum normalized positive T number.
    static const T   maximum;            // Maximum normalized positive T number.
    static const T   epsilon;            // Minimum x such that 1.0 + x != x.

    static const int digits;             // decimal digits of precision.
    static const int radix;              // exponent representation radix.
    static const int mantissa_digits;    // number of base radix digits in mantissa;

    static const int min_exponent;       // pow(radix,min_exponent - 1) is ok.
    static const int min_10_exponent;    // pow(10,min_10_exponent) is ok.
    static const int max_exponent;       // pow(radix,max_exponent - 1) is ok.
    static const int max_10_exponent;    // pow(10,max_10_exponent) is ok.

};



#include <float.h>


const float  NumericalLimits<float>::minimum            = FLT_MIN;
const float  NumericalLimits<float>::maximum            = FLT_MAX;
const float  NumericalLimits<float>::epsilon            = FLT_EPSILON;
// ...

const double NumericalLimits<double>::minimum           = DBL_MIN;
const double NumericalLimits<double>::maximum           = DBL_MAX;
const double NumericalLimits<double>::epsilon           = DBL_EPSILON;
// ...



const int NumericalLimits<float>::digits = FLT_DIG;
const int NumericalLimits<float>::radix = FLT_RADIX;
const int NumericalLimits<float>::mantissa_digits = FLT_MANT_DIG;
const int NumericalLimits<float>::min_exponent = FLT_MIN_EXP;
const int NumericalLimits<float>::min_10_exponent = FLT_MIN_10_EXP;
const int NumericalLimits<float>::max_exponent = FLT_MAX_EXP;
const int NumericalLimits<float>::max_10_exponent = FLT_MAX_10_EXP;

const int NumericalLimits<double>::digits = DBL_DIG;
const int NumericalLimits<double>::radix = FLT_RADIX;
const int NumericalLimits<double>::mantissa_digits = DBL_MANT_DIG;

const int NumericalLimits<double>::min_exponent = DBL_MIN_EXP;
const int NumericalLimits<double>::min_10_exponent = DBL_MIN_10_EXP;
const int NumericalLimits<double>::max_exponent = DBL_MAX_EXP;
const int NumericalLimits<double>::max_10_exponent = DBL_MAX_10_EXP;

const long double NumericalLimits<long double>::minimum = LDBL_MIN;
const long double NumericalLimits<long double>::maximum = LDBL_MAX;
const long double NumericalLimits<long double>::epsilon = LDBL_EPSILON;

const int NumericalLimits<long double>::digits = LDBL_DIG;
const int NumericalLimits<long double>::radix = FLT_RADIX;
const int NumericalLimits<long double>::mantissa_digits = LDBL_MANT_DIG;

const int NumericalLimits<long double>::min_exponent = LDBL_MIN_EXP;
const int NumericalLimits<long double>::min_10_exponent = LDBL_MIN_10_EXP;
const int NumericalLimits<long double>::max_exponent = LDBL_MAX_EXP;
const int NumericalLimits<long double>::max_10_exponent = LDBL_MAX_10_EXP;

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// Compile test only
#include <math.h>  /* Include to get consistency check with math dcl's below */
#include <complex>  /* Likewise... */

using std::complex;

extern int day_of_year;
extern double f(double);


int day_of_year = 31;
double f(double x) {
    return 1.0 / x;
}

// CAD: better use the declarations from math.h, 
// which are inconsistent with these
// extern double sin(double);
// extern double atan2(double x1, double x2);// C++ function for arctan
// extern double  sin(double x);
// extern double cos(double x);
// extern double sin(double x);

extern complex<double> sin(complex<double> x);


extern int g(double);      // File scope, type: int (::)(double);

class X {
public:
int g(double);             // class X scope, type: int (X::)(double);
};



extern double x;


double x;

#if 0


extern double sin(double x);
extern float  sin(double x);// WRONG: Return type differs from previous return type


#endif

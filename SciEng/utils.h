/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef utilsH
#define utilsH

namespace sce{

template<class T> inline T min(T x1, T x2) { return x1 < x2 ? x1 : x2; }

template<class T> inline T max(T x1, T x2) { return x1 > x2 ? x1 : x2; }

template<class T> 
inline
T sqr(T x) { 
    return x * x; 
}

// FIXME: should test for xlC compiler instead of !GNUC

#ifndef __GNUC__

class complex;
extern double abs(complex);    // should return double, not complex
                               // This dcl prevents the template from being expanded,
                               // so the library routine can be used

// Following to handle xlC bug abscomp.C
#include <complex.h>
inline
double abs(complex z) {
  // Algorithm from Numerical methods
  double x = fabs(real(z));
  double y = fabs(imag(z));
  double ans;
  if (x == 0.0) ans =  y;
  else if (y == 0.0) ans =  x;
  else if (x > y) {
    double temp = y/x;
    ans =  x * sqrt(1+temp*temp);
  } else {
    double temp = x/y;
    ans =  y * sqrt(1+temp*temp);
  }
  return ans;
}
  
// End bug workaround
#endif  


template<class T> T abs(T x)        { return x < 0   ? -x : x;  }

}

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Algebra/ComplexFloat.h"
#include <math.h>
#include <iostream.h>

ComplexFloat& ComplexFloat::operator/=(const ComplexFloat& rhs) {
  // Implements equation 5.4.5, Numerical Recipes in C, second ed.
  // Give shorter names: compute (a + ib)/(c + id)
  float& a = real_part;
  float& b = imag_part;
  const float& c = rhs.real_part;
  const float& d = rhs.imag_part;

  // Choose part of denominator to factor out
  if (fabs(c) >= fabs(d)) {
     float d_over_c = d / c;
     float denom = c + d * d_over_c;
     float r = a + b * d_over_c;
     float i = b - a * d_over_c;
     a = r / denom;
     b = i / denom;
  }
  else {
     float c_over_d = c / d;
     float denom = c * c_over_d + d;
     float r = a * c_over_d + b;
     float i = b * c_over_d - a;
     a = r / denom;
     b = i / denom;
  }
  return *this;
}

ostream& operator<<(ostream& os, ComplexFloat c) {
  os << c.real();
  if      (c.imag() > 0)  os << '+' << c.imag() << 'i';
  else if (c.imag() == 0) os << '+' << "0i";
  else                    os << '-' << -c.imag() << 'i';
  return os;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <complex>
#include "SciEng/utils.h"

// GNUC g++/std/complex.h: typedef complex<double> double_complex;
// or in egcs-1.0.2/libstdc++/complex

#ifndef __GNUC__
typedef complex<double>  double_complex;
#endif

void create_more_templates(void);

int main() {

  int i = 1;
  float f = 3.1;
  double d = 4.4;
  double_complex c(3, 4);
  double_complex c1(6, 8);

  //  using SciEngLib::sqr;

  cout << "sqr(i) " << sqr(i) << endl; // Generate sqr(int)
  cout << "sqr(f) " << sqr(f) << endl; // Generate sqr(float)
  cout << "sqr(d) " << sqr(d) << endl; // Generate sqr(double)
  cout << "sqr(c) " << sqr(c) << endl; // Generate sqr(complex)
  cout << "sqr(c1) " << sqr(c1) << endl; // Generate sqr(complex)

  create_more_templates();

  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <complex.h>
#include "SciEng/utils.h"

int main() {

  int i = 1;
  float f = 3.1;
  double d = 4.4;
  complex c(3, 4);

  cout << sqr(i) << endl; // Generate sqr(int)
  cout << sqr(f) << endl; // Generate sqr(float)
  cout << sqr(d) << endl; // Generate sqr(double)
  cout << sqr(c) << endl; // Generate sqr(complex)


  return 0;
}

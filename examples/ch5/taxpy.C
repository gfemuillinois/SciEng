/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch5/axpy.h"
#include <complex>

typedef std::complex<double> double_complex;

int main() {

  Vector<double> a(4);
  Vector<int> ai(4);
  Vector< double_complex > ac(4);
  Vector<double> b(4); 
  Vector<int> bi(4); 
  Vector< double_complex > bc(4); 

  // Initialize a, b, ai, and bi ...

  a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
  ai[0] = 1; ai[1] = 2; ai[2] = 3; ai[3] = 4;
  ac[0] = 1; ac[1] = 2; ac[2] = 3; ac[3] = 4;
  b[0] = 11; b[1] = 12; b[2] = 13; b[3] = 14;
  bi[0] = 11; bi[1] = 12; bi[2] = 13; bi[3] = 14;
  bc[0] = 11; bc[1] = 12; bc[2] = 13; bc[3] = 14;

 axpy(10.0, a, b);   // Matches template with EltType = double
 axpy(10, ai, bi);   // Matches template with EltType = int
/*
 axpy(10, a, b);     // Incorrect: no match
 axpy(10.0, ac, bc); // Incorrect: no match
*/


  if (b[0] != 21 || b[1] != 32 || b[2] != 43 || b[3] != 54) return 1;
  if (bi[0] != 21 || bi[1] != 32 || bi[2] != 43 || bi[3] != 54) return 1;
  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Algebra/ComplexFloat.h"
#include "examples/ch5/axpy.h"
#include <complex>

using std::complex;

/*
  // These declarations will prevent template expansion.
  // This trick to allow argument convertion is not supported by ANSI C++
  // (unless the functions below are defined)
  // We can use explicity template argument (see below)
extern void axpy(float        alpha, const Vector<float>&        x, Vector<float>&   y);
extern void axpy(double       alpha, const Vector<double>&       x, Vector<double>&  y);


extern void axpy(ComplexFloat alpha, const Vector<ComplexFloat>& x, 
                 Vector<ComplexFloat>& y);
extern void axpy(complex<double> alpha, const Vector<complex<double> >&
		 x, Vector<complex<double> >& y);
*/


int main() {
  Vector<double> a(4);
  Vector<int> ai(4);
  Vector<complex<double> > ac(4);
  Vector<double> b(4); 
  Vector<int> bi(4); 
  Vector<complex<double> > bc(4); 
  // Initialize a, b, ai, and bi ...
  a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
  ai[0] = 1; ai[1] = 2; ai[2] = 3; ai[3] = 4;
  ac[0] = 1; ac[1] = 2; ac[2] = 3; ac[3] = 4;
  b[0] = 11; b[1] = 12; b[2] = 13; b[3] = 14;
  bi[0] = 11; bi[1] = 12; bi[2] = 13; bi[3] = 14;
  bc[0] = 11; bc[1] = 12; bc[2] = 13; bc[3] = 14;


 axpy(10.0, a, b);   // Matches template with EltType = double
 axpy(10, ai, bi);   // Matches template with EltType = int
 b[0] = 11; b[1] = 12; b[2] = 13; b[3] = 14;


 // Using explicity template arguments
 axpy<double>(10, a, b); // Instantiate template with EltType = double
 axpy<complex<double> >(10.0, ac, bc); // Instantiate template with EltType = complex<double>

 // This is not supported by ANSI C++ (unless the functions below are defined)
 // axpy(10, a, b);     // Matches axpy(double, const Vector<double>&, Vector<double>&)
 // axpy(10.0, ac, bc); // Matches axpy(complex<double>, const Vector<complex<double> >&, Vector<complex<double> >&)


  if (b[0] != 21 || b[1] != 32 || b[2] != 43 || b[3] != 54) return 1;
  if (bi[0] != 21 || bi[1] != 32 || bi[2] != 43 || bi[3] != 54) return 1;
  //  if (bc[0] != 21 || bc[1] != 32 || bc[2] != 43 || bc[3] != 54) return 1;
  return 0;
}

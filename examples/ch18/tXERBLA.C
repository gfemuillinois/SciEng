/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

#include "SciEng/SciEngEnvironment.h"
#include "LapackWrap/BlasSubroutines.h"

#include "clarch.h"

// SciEngStartup initialize_SciEngErr;

// Tests the FORTRAN calling C++ example xerbla() in BlasSubroutines.h

int main(){

  float x[10] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9.};
  float y[10] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9.};

  // NOTE: This is an invalid test since xerbla is NOT called by
  //       snrm2 if a bad argument is given. It simply sets the
  //       return value to 0
  // Apparently, xerbla is only called by blas2 blas3 and lapack
  try {                        
    float norm = Blas1Subroutines::xnrm2(10, x, -1); // Bad third argument
    cout << "norm = " << norm << endl;
 
    float dot = Blas1Subroutines::xdot(10, x, 1, y, -1); // bad last argument
    cout << "x dot y = " << dot << endl;

  } catch(const BlasErr& e) {
    userErrMessage(e);
    cerr << "Test for xerbla trap succeeds" << endl;
    return 0;
  }

  int m = 2, n = 2, lda = 2, incu = 1, incb = 1;
  double alpha = 1.0, beta = 0.0;
  double a[2*2] = {1., 0., 0., 1.};
  double b[2], u[2] = {1., 1.};

  try {

    lda = -2; // Bad argument
    Blas2Subroutines::xgemv( Blas2Subroutines::no_trans, m, n, alpha,
			     a, lda, 
			     u, incu, beta,
			     b, incb);
    cout << "a * u = " << b[0] << " " << b[1] << endl;

    /*
    const char no_trans = 'N';
    lda = -2; // Bad argument
    FTNAME(dgemv)( &no_trans, m, n, alpha,
		   a, lda, 
		   u, incu, beta,
		   b, incb);
    cout << "a * u = " << b[0] << " " << b[1] << endl;
    */

  } catch(const BlasErr& e) {

    userErrMessage(e);
    cerr << "Test for xerbla trap succeeds" << endl;
    return 0;

  }

  return 1;
}

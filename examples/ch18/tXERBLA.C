/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/SciEngEnvironment.h"
#include "LapackWrap/BlasSubroutines.h"

// Tests the FORTRAN calling C++ example xerbla() in BlasSubroutines.h

main(){

  float x[10];
  // ... set x ...
  try {                        
    float norm = Blas1Subroutines::xnrm2(10, x, 0); // Bad third argument
} catch(const BlasErr& e) {
    userErrMessage(e);
    cerr << "Test for xerbla trap succeeds" << endl;
    return 0;
}

  return 1;
}

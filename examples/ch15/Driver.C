/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// Illustrate a function like Lapack's simple drivers

#include <iostream.h>
#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectLURep.h"
#include "LapackWrap/SymPosDefPackedLURep.h"

#include "Driver.h"

int
main() {

  LapackUnfactored< RectLURep<double> > a1(2, 2);
  a1(0,0) = 2;  a1(0,1) = 3;
  a1(1,0) = 5;  a1(1,1) = 6;
  
  ConcreteFortranArray2d<double> b1(2, 1);
  b1(0,0) = 4; 
  b1(1,0) = 7; 
  
  cout << xForAxEqb(a1, b1) << endl;


  LapackUnfactored< SymPosDefPackedLURep<float> > a2(2, 2);
  a2(0,0) = 2;  a2(0,1) = -2;
                a2(1,1) =  5;

  ConcreteFortranArray2d<float>  b2(2, 2);
  b2(0,0) =-2;  b2(0,1) = 2;
  b2(1,0) = 8;  b2(1,1) = -8;
    
  cout << xForAxEqb(a2, b2) << endl;

  return 0;
}

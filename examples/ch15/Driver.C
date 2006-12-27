/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// Illustrate a function like Lapack's simple drivers

#include <iostream>
#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectLURep.h"
#include "LapackWrap/SymPosDefPackedLURep.h"
#include "Array/ConcreteFormedArray2d.h"
#include "Array/ConcreteFortranArray3d.h"
#include "Array/ConcreteFormedArray3d.h"

#include "Driver.h"

using std::cout;
using std::cin;
using std::endl;

int
main() {
  // cad: just testing projections
  ConcreteFortranArray1d<double> cf1d(2);
  cf1d = 10.0;
  cout << "\ncf1d: " << cf1d << endl;
  cf1d[0] = 0.0;
  cf1d[1] = 1.0;
  cout << "cf1d: " << cf1d << endl;
 

  ConcreteFortranArray2d<double> cf2d(1, 2), cf2d_a(2,1);
  cf2d = 10.0;
  cout << "\ncf2d: " << cf2d << endl;
  cf2d.column(0) = 0.0;
  cf2d.column(1) = 1.0;
  cout << "cf2d: " << cf2d << endl;

  cf2d_a = 10.0;
  cout << "\ncf2d_a: " << cf2d_a << endl;
  cf2d_a[0] = 0.0;
  cf2d_a[1] = 1.0;
  cout << "cf2d_a: " << cf2d_a << endl;

  ConcreteFormedArray2d<double> cfm2d(1, 2), cfm2d_a(2,1);
  cfm2d = 10.0;
  cout << "\ncfm2d: " << cfm2d << endl;
  cfm2d.column(0) = 0.0;
  cfm2d.column(1) = 1.0;
  cout << "cfm2d: " << cfm2d << endl;
 
  cfm2d_a = 10.0;
  cout << "\ncfm2d_a: " << cfm2d_a << endl;
  cfm2d_a[0] = 0.0;
  cfm2d_a[1] = 1.0;
  cout << "cfm2d_a: " << cfm2d_a << endl;

  /* CAD: Could not compile this with gcc 4.1.2

  ConcreteFormedArray3d<double> cfm3d(2, 1, 1);
  cfm3d = 10.0;
  cout << "\ncfm3d: " << cfm3d << endl;
  cfm3d[0] = 0.0;
  cfm3d[1] = 1.0;
  cout << "cfm3d: " << cfm3d << endl;


  ConcreteFortranArray3d<double> cf3d(2, 1, 1);
  cf3d = 10.0;
  cout << "\ncf3d: " << cf3d << endl;
  cf3d[0] = 0.0;
  cf3d[1] = 1.0;
  cout << "cf3d: " << cf3d << endl;

  */
  // Tests for Lapack stuff

  LapackUnfactored< RectLURep<double> > a1(2, 2);
  a1(0,0) = 2;  a1(0,1) = 3;
  a1(1,0) = 5;  a1(1,1) = 6;

  ConcreteFortranArray2d<double> b1(2, 1);
  b1(0,0) = 40; 
  b1(1,0) = 70; 
  cout << "\nb1: " << b1 << endl;

  b1[0] = 4.0;
  b1[1] = 7.0;
  cout << "b1: " << b1 << endl;
 
  cout << "Solution: (must be [-1],[2]) : " << endl;
  cout << xForAxEqb(a1, b1) << endl;


  LapackUnfactored< SymPosDefPackedLURep<float> > a2(2, 2);
  a2(0,0) = 2;  a2(0,1) = -2;
                a2(1,1) =  5;

  ConcreteFortranArray2d<float>  b2(2, 2);
  b2(0,0) =-2;  b2(0,1) = 2;
  b2(1,0) = 8;  b2(1,1) = -8;
  cout << "\nb2: " << b2 << endl;

  cout << "Solution: (must be [1,-1], [2, -2]) : " << endl;
  cout << xForAxEqb(a2, b2) << endl;

  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFormedArray2d.h"
#include "Array/ConcreteFormedArray3d.h"
#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"
#include "Array/ConcreteFortranArray2d.h"

#include "SciEng/utils.h"

#include "tConcreteMax.h"

using std::cout;
using std::endl;

int main() {


  ConcreteFormedArray2d<int> a1(3, 4);      // 3x4 array of ints
  ConcreteRigidArray2d<float, 5, 6> a2;     // 5x6 array of floats
  ConcreteFortranArray2d<double> a3(7, 8);  // 7x8 array of doubles

  // ... set elements ...
  a1 = -1; a1(1,2) = 3;
  a2 = -1; a2(1,2) = 3;
  a3 = -1; a3(1,2) = 3;
  cout << "max element of a1 is " << maxArray2dElement(a1) << endl;
  cout << "max element of a2 is " << maxArray2dElement(a2) << endl;
  cout << "max element of a3 is " << maxArray2dElement(a3) << endl;

  ConcreteFormedArray1d<float> f1(5);
  ConcreteFormedArray1d<float> f2(5);
  f1 = 130.0;
  f2 = f1;


  {

    ConcreteFormedArray2d<int> a(3, 4);

    a(0,0)=1;   a(0,1)=2;   a(0,2)=3;   a(0,3)=4;
    a(1,0)=5;   a(1,1)=6;   a(1,2)=7;   a(1,3)=8;
    a(2,0)=9;   a(2,1)=10;  a(2,2)=11;  a(2,3)=12;


    cout << a.project(0, 0) << endl;   // Prints: [1, 2, 3, 4]
    cout << a.project(1, 0) << endl;   // Prints: [5, 6, 7, 8]
    cout << a.project(2, 0) << endl;   // Prints: [9, 10, 11, 12]

    cout << a.project(0, 1) << endl;   // Prints: [1, 5, 9]
    cout << a.project(1, 1) << endl;   // Prints: [2, 6, 10]
    cout << a.project(2, 1) << endl;   // Prints: [3, 7, 11]
    cout << a.project(3, 1) << endl;   // Prints: [4, 8, 12]

    
    cout << a[0] << endl;   // Prints: [1, 2, 3, 4]
    cout << a[1] << endl;   // Prints: [5, 6, 7, 8]
    cout << a[2] << endl;   // Prints: [9, 10, 11, 12]


    cout << a[1][2] << endl;// Prints: 7
    
    a.project(0, 1) = 1;
    
    a.project(0, 0) = 2;
    
    a[0] = 2;

  }
  {

    ConcreteFormedArray3d<int> fa(2, 3, 4);
    // ... set fa ...
    fa = 0;
    fa(1, 0, 0) = 1;

    cout << "fa = " << fa << endl;

    //maxArray3dPlane(fa) = -1;
    
    Subscript plane_with_max = maxArray3dPlane(fa);

    fa[ plane_with_max ] = -1;

    cout << "fa = " << fa << endl;

  }
  return 0;
}

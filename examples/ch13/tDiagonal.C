/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "Array/FormedArray2d.h"

#include "Array/Array2d.h"
#include "Array/Array1d.h"
#include "SciEng/utils.h"

#include "tDiagonal.h"

int
main() {
  FormedArray2d<int> a(5, 4);
  a = 3;
  DiagonalOfArray2d<int> d(a);
  d = 1;
  cout << "Diagonal is " << d << endl << "Matrix is " << a << endl;
  set_to_identity(a);
  cout << "Identity is " << a << endl;
  return 0;
}

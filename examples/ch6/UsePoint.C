/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "examples/ch6/Point.h"

static void f() {

  Point p1(2, 3);

  cout << p1.x() << endl;  // Uses non-const x()
  p1.x() = 1;              // Uses non-const x()
  p1.y() = 2;              // Uses non-const y()

  const Point p2 = p1;
  cout << p2.x() << endl;  // Uses const x()
/*
  p2.x() = 3;              // WRONG: Operand of = must be an lvalue (Uses const x())
  p2.y() = 4;              // WRONG: Operand of = must be an lvalue (Uses const x())
*/


}

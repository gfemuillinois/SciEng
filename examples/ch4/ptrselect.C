/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "examples/ch4/Point.h"

int main() {

  Point p1(1, 2);
  Point* p_ptr;
  // ... set p_ptr ...
  p_ptr = new Point(2,2); 
  cout << p_ptr->distance(p1) << endl;

  delete p_ptr;
  return 0;
}

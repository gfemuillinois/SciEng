/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/FormedArray.h"
#include "Array/RigidArray.h"
#include "examples/ch11/sum.h"

int main() {
  {

    FormedArray2d<double> f(5, 5);
    f = 4;
    double d = sum(f);

    if (d != 100) return 1;
  }
  {

    RigidArray2d<double,5,5> f(5, 5);
    f = 4;
    double d = sum(f);

    if (d != 100) return 1;
  }
  {

    FormedArray2d<int> f(5, 5);
    f = 4;
    int d = sum(f);

    if (d != 100) return 1;
  }
  return 0;
}

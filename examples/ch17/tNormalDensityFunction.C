/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "Function/NormalDensityFunction.h"

int main() {

  NormalDensityFunction<double> std_normal(0.0, 1.0);
  NormalDensityFunction<double> std_biased(1.0, 1.0);


  cout << std_normal(0.0) << " " << std_normal(1.0) << endl;
  cout << std_biased(0.0) << " " << std_biased(1.0) << endl;

  return 0;
}

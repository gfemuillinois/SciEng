/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Function/FunctionalAlgebra.h"

int main(){
  {

  FunctionalAlgebra<double> x;  // Variable by default.
  FunctionalAlgebra<double> f = x + x;
  cout << f(5) << endl;

  }
  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "Function/GaussianFunctional.h"
#include "Function/FunctionalAlgebra.h"
#include "SciEng/Ptrs.h"


int main() {

  CountedBuiltInPtr<double> p_mean(new double);
  FunctionalAlgebra<double> mean(p_mean);
  FunctionalAlgebra<double> width1(1.0);
  FunctionalAlgebra<double> width2(2.0);
  GaussianFunctional<double> g1(mean, width1);
  GaussianFunctional<double> g2(mean, width2);
  FunctionalAlgebra<double> f = g1 + g2;


  *p_mean = 0.0;
  cout << f(.5) << endl;
  *p_mean = 2.0;
  cout << f(.5) << endl;


  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "DataModeling/GaussianDeviates.h"

#include <math.h>

GaussianDeviates::GaussianDeviates(int seed) :
  ran(seed),
  one_saved(Boolean::false),
  saved_one(0) {
}
                         
double GaussianDeviates::operator()() {
  // From Numerical Recipes in C,
  //  Press, Flannery, Teukolsky, Vetterling
  // 1st ed, section 7.2
  if(one_saved) {
    one_saved = Boolean::false;
    return saved_one;
  }
  double r;
  double v1;
  double v2;
  do {
    v1 = 2.0 * ran() - 1.0;  // Two deviates in square +/- 1.0
    v2 = 2.0 * ran() - 1.0;
    r = v1*v1 + v2*v2;
  } while (r >= 1.0);        // Two deviates inside unit circle.
  // Box-Muller transform
  double fac = sqrt(-2.0*log(r)/r);
  saved_one = v1*fac;
  one_saved = Boolean::true;
  return v2*fac;
}

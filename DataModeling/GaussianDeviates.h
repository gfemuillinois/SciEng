/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GaussianDeviatesH
#define GaussianDeviatesH

#include "SciEng/Boolean.h"
#include "DataModeling/UniformDeviates.h"
                      
class GaussianDeviates {
public:
  GaussianDeviates(int seed);
  double operator()();
private:
  UniformDeviates ran;
  Boolean one_saved;
  double saved_one;
};
      
#endif

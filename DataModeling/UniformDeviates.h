/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef UniformDeviatesH
#define UniformDeviatesH

#include <stdlib.h>
                               
class UniformDeviates {
public:
   UniformDeviates(int seed) { srand48(seed); }
   double operator()() const { return drand48(); }
private:
  //   int seed;
};
      
#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CachingFunctionH
#define CachingFunctionH

#include "Function/Function.h"

template<class Domain, class Range>
class CachingFunction :
  public Function<Domain, Range> {
public:
  CachingFunction( Range(*f)(Domain) ) : 
    Function<Domain,Range>(f), 
    first_time(1) {
  }
  virtual Range operator()(const Domain& x) const { return Function<Domain,Range>::operator()(x); }
  virtual Range operator()(const Domain& x)       {
    if (first_time || x != previous_x) {
      first_time = 0;
      previous_x = x;
      previous_result = pf(x);
    }
    return previous_result;
  }
private:
   int first_time;
   float previous_x;
   float previous_result;
};

#endif

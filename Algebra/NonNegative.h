/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NonNegativeH
#define NonNegativeH

#include "Algebra/SubDomain.h"
#include "Algebra/Positive.h"

template<class T>
class NonNegativePredicate {
public:
  static Boolean isSatisfied(const T& x) {
    return x >= 0;
  }
  static String description() {
    return  "is not non-negative";
  }
};

template<class T>
class NonNegative : public SubDomain<T, NonNegativePredicate<T> > {
public:
  NonNegative(const T& x) : SubDomain<T, NonNegativePredicate<T> >(x) {}
  NonNegative(const Positive<T>& x) : SubDomain<T, NonNegativePredicate<T> >(x) {}
};
#endif

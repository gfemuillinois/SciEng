/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingGroupH
#define DistributingGroupH

#include "Vector/DistributingMonoid.h"

template<class Array, class T>
class DistributingGroup :
  public DistributingMonoid<Array, T> {
public:
  Array& operator/=(const Array& rhs) { return Distribute2<Div,Array>::over((Array&) *this, rhs); }
private:
  class Div { public: Div(T& lhs, const T& rhs) { lhs /= rhs; } };
};

#endif

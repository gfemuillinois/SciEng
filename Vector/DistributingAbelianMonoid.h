/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingAbelianMonoidH
#define DistributingAbelianMonoidH

#include "Vector/DistributingAbelianSemiGroup.h"

template<class Array, class T>
class DistributingAbelianMonoid :
  public DistributingAbelianSemiGroup<Array, T> {
public:
  Array& setToZero() { return Distribute1<SetZero,Array>::over((Array&) *this); }
private:
  class SetZero { public: SetZero(T& lhs) { lhs = T(0); } };
};

#endif

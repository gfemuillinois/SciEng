/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingMonoidH
#define DistributingMonoidH

#include "Vector/DistributingSemiGroup.h"

template<class Array, class T>
class DistributingMonoid :
  public DistributingSemiGroup<Array, T> {
public:
  Array& setToOne() { return Distribute1<SetOne,Array>::over((Array&) *this); }
private:
  class SetOne { public: SetOne(T& lhs) { lhs = T(1); } };
};

#endif

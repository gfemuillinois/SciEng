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
  Array& operator/=(const Array& rhs) { 
    return Distribute2<Div,Array>::over((Array&) *this, rhs); }

  // provided by class DistributingFieldScalars
  // CAD:
  //  Array& operator/=(const T& rhs) { 
  //  return DistributeS<Div,Array,T>::over((Array&) *this, rhs); }

  // lhs(i) = x(i) / y(i)
  friend void XdivY(Array& lhs, const Array& x, const Array& y) {
    Distribute3<Div2, Array>::over( lhs, x, y ); } 

  // z(i) = x(i) / y(i)
  friend void distDiv(const Array& x, const Array& y, Array& z) {
    Distribute3<Div2, Array>::over( z, x, y ); } 

private:
  class Div { public: Div(T& lhs, const T& rhs) { lhs /= rhs; } };

  // CAD
  class Div2 { public: Div2 (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 / rhs1; } };
};

#endif

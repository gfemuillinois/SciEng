/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingSemiGroupH
#define DistributingSemiGroupH

#include "Vector/Distribute.h"

template<class Array, class T>
class DistributingSemiGroup {
public:
  Array& operator*=(const Array& rhs) { 
    return Distribute2<Mult,Array>::over((Array&) *this, rhs); }

  // provided by class DistributingExternalScalars
  // CAD:
  //  Array& operator*=(const T& rhs) { 
  //  return DistributeS<Mult,Array,T>::over((Array&) *this, rhs); }

  // lhs(i) = x(i) * y(i)
  friend void XtimesY(Array& lhs, const Array& x, const Array& y) {
    Distribute3<Mult2, Array>::over( lhs, x, y ); } 

  // z(i) = x(i) * y(i)
  friend void distMult(const Array& x, const Array& y, Array& z) {
    Distribute3<Mult2, Array>::over( z, x, y ); } 

private:
  class Mult { public: Mult(T& lhs, const T& rhs) { lhs *= rhs; } };

  // CAD
  class Mult2 { public: Mult2 (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 * rhs1; } };
};

#endif

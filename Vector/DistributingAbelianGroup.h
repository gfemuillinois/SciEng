/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingAbelianGroupH
#define DistributingAbelianGroupH

#include "Vector/DistributingAbelianMonoid.h"


template<class Array, class T>
class DistributingAbelianGroup : 
    public DistributingAbelianMonoid<Array, T> {
public:
    Array& operator-=(const Array& rhs) { 
      return Distribute2<Sub,Array>::over((Array&) *this, rhs); }

  // Moved to DistributingFieldScalars
  // CAD:
  //  Array& operator-=(const T& rhs) { 
  //    return DistributeS<Sub,Array,T>::over((Array&) *this, rhs); }

  // lhs = x - y
  friend void XminusY(Array& lhs, const Array& x, const Array& y) {
    Distribute3<Sub2, Array>::over( lhs, x, y ); } 

  // z = x - y
  friend void sub(const Array& x, const Array& y, Array& z) {
    Distribute3<Sub2, Array>::over( z, x, y ); } 


private:
    class Sub { public: Sub(T& lhs, const T& rhs) { lhs -= rhs; } };

  // CAD
  class Sub2 { public: Sub2 (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 - rhs1; } };
};


#endif

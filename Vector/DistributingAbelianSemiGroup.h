/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingAbelianSemiGroupH
#define DistributingAbelianSemiGroupH

#include "Vector/Distribute.h"


template<class Array, class T>
class DistributingAbelianSemiGroup {             
public:
    Array& operator+=(const Array& rhs) { 
      return Distribute2<Add,Array>::over((Array&) *this, rhs); }

  // Moved to DistributingExternalScalars
  // CAD: 
  //  Array& operator+=(const T& rhs) { 
  //  return DistributeS<Add,Array,T>::over((Array&) *this, rhs); }

  // lhs = x + y
  friend void XplusY(Array& lhs, const Array& x, const Array& y) {
    Distribute3<Add2, Array>::over( lhs, x, y ); } 

  // z = x + y
  friend void add(const Array& x, const Array& y, Array& z ) {
    Distribute3<Add2, Array>::over( z, x, y ); } 


private:
    class Add { public: Add(T& lhs, const T& rhs) { lhs += rhs; } };

  // CAD
  class Add2 { public: Add2 (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 + rhs1; } };
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingExternalScalarsH
#define DistributingExternalScalarsH

#include "Vector/Distribute.h"

template<class Array, class T, class S>
class DistributingExternalScalars {
public:
  Array& operator*=(const S& rhs) { 
    return DistributeS<Mult,Array,T>::over((Array&) *this, rhs); }

  // CAD:
  Array& operator+=(const S& rhs) { 
    return DistributeS<Add,Array,S>::over((Array&) *this, rhs); }  
  
  // lhs(i) = rhs(i) + s
  friend void XplusScalar(Array& lhs, const Array& x, const S& s) {
    DistributeS<Add2, Array, S>::over( lhs, x, s ); }
  
  // y(i) = x(i) + s
  friend void add(const Array& x, const S& s, Array& y) {
    DistributeS<Add2, Array, S>::over( y, x, s ); }


  // lhs(i) = rhs(i) * s
  friend void XmultScalar(Array& lhs, const Array& x, const S& s) {
    DistributeS<Mult2, Array, S>::over( lhs, x, s ); }

  // y(i) = x(i) * s
  friend void scale(const Array& x, const S& s, Array& y) {
    DistributeS<Mult2, Array, S>::over( y, x, s ); }    

  // y(i) = x(i) * s
  friend void mult(const Array& x, const S& s, Array& y) {
    DistributeS<Mult2, Array, S>::over( y, x, s ); }    

private:
  class Mult { public: Mult(T& lhs, const S& rhs) { lhs *= rhs; } };

  // CAD:
  class Mult2 { public: Mult2 (T& lhs, const T& rhs0, const S& rhs1) { lhs = rhs0 * rhs1; } };

  class Add  { public: Add (T& lhs, const S& rhs) { lhs += rhs; } };

  class Add2 { public: Add2 (T& lhs, const T& rhs0, const S& rhs1) { lhs = rhs0 + rhs1; } };

};

#endif

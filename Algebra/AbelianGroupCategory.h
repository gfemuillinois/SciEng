/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AbelianGroupCategoryH
#define AbelianGroupCategoryH

#include "Algebra/AbelianMonoidCategory.h"
#include "Algebra/GroupCommon.h"


template<class T>
class AbelianGroupCategory : public AbelianMonoidCategory<T> {
public: 
    // User Must Define: T& operator-=(const T&);
    inline T& repeat(int n);
    inline T& negate();


    friend T operator-(const T& lhs, const T& rhs) { T temp(lhs); return temp -= rhs; }
    friend T operator-(const T& x)                 { T temp(x); return temp.negate(); }



    static void composeWithInverse(T& lhs, const T& rhs) { lhs -= rhs; }
    static void selfInversion(T& x)                      { x.negate(); }

};


template<class T>
inline
T& AbelianGroupCategory<T>::negate() { 
  T& self = (T&) *this;
  T temp(self);
  self.setToZero();
  return self -= temp;
}

template<class T>
inline T& AbelianGroupCategory<T>::repeat(int n) {
  return GroupCommon<T, AbelianGroupCategory<T> >::repeatedComposition((T&) *this, n);
}

#endif

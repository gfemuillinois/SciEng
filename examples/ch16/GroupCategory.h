/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GroupCategoryH
#define GroupCategoryH

#include "Algebra/MonoidCategory.h"
#include "Algebra/GroupCommon.h"


template<class T>
class GroupCategory : public MonoidCategory<T> {
    public:
    // User Must Define: T& operator/=(const T&);
    inline T&       pow(int n);
    inline T&       invert();


    friend T operator/(const T& lhs, const T& rhs) { T temp(lhs); return temp /= rhs; }
    friend T inverse(const T& x)                   { T temp(x); return temp.invert(); }



    static void composeWithInverse(T& lhs, const T& rhs) { lhs /= rhs; }
    static void selfInversion(T& x)                      { x.invert(); }

};


template<class T>
inline T& GroupCategory<T>::pow(int n) {
  return GroupCommon<T, GroupCategory<T> >::repeatedComposition((T&) *this, n);
}

template<class T>
inline T& GroupCategory<T>::invert() {
    T& self = (T&) *this;
    T temp(self);
    self.setToOne();
    return self /= temp;
}

#endif


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SemiGroupCategoryH
#define SemiGroupCategoryH

#include "Algebra/SemiGroupCommon.h"
#include "Algebra/Positive.h"


template<class T>
class SemiGroupCategory {
public:
    // User Must Define: T& operator*=(const T&);

    friend T operator*(const T& lhs, const T& rhs) { T temp(lhs); return temp *= rhs; }
    friend T pow(const T& x, int n)                { T temp(x); return temp.pow(n);   }

    inline T& pow(Positive<int> n);

    static void compositionLaw(T& lhs, const T& rhs) { lhs *= rhs; }
};



template<class T>
inline T& SemiGroupCategory<T>::pow(Positive<int> n) {
    return SemiGroupCommon<T, SemiGroupCategory<T> >::repeatedComposition((T&) *this, n);
}


#endif


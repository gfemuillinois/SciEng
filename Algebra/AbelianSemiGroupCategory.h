/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AbelianSemiGroupCategoryH
#define AbelianSemiGroupCategoryH


#include "Algebra/SemiGroupCommon.h"
#include "Algebra/Positive.h"


template<class T>
class AbelianSemiGroupCategory {
public:
    // User Must Define: T& operator+=(const T&);

    friend T operator+(const T& lhs, const T& rhs)  { T temp(lhs); return temp += rhs;    }
    friend T repeat(const T& x, int n)              { T temp(x); return temp.repeat(n);   }

    inline T& repeat(Positive<int> n); 

    static void compositionLaw(T& lhs, const T& rhs)  { lhs += rhs; }
};



template<class T>
inline T& AbelianSemiGroupCategory<T>::repeat(Positive<int> n) { 

    return SemiGroupCommon<T, AbelianSemiGroupCategory<T> >::
               repeatedComposition((T&) *this, n);

}


#endif

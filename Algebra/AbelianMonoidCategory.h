/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AbelianMonoidCategoryH
#define AbelianMonoidCategoryH

#include "Algebra/AbelianSemiGroupCategory.h"
#include "Algebra/MonoidCommon.h"
#include "Algebra/NonNegative.h"


template<class T>
class AbelianMonoidCategory : public AbelianSemiGroupCategory<T> {
public: 
    // User Must Define: T& setToZero();
    inline T& repeat(NonNegative<int> n);

    static void identityElement(T& x) { x.setToZero(); }
};

template<class T>
inline 
T& AbelianMonoidCategory<T>::repeat(NonNegative<int> n) { 
    return MonoidCommon<T, AbelianMonoidCategory<T> >::repeatedComposition((T&) *this, n);
}


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MonoidCategoryH
#define MonoidCategoryH

#include "Algebra/SemiGroupCategory.h"
#include "Algebra/MonoidCommon.h"
#include "Algebra/NonNegative.h"


template<class T>
class MonoidCategory : public SemiGroupCategory<T> {
public:
    // User Must Define: T& setToOne();
    inline T& pow(NonNegative<int> n);

    static void identityElement(T& x) { x.setToOne(); }
};


template<class T>
inline T& MonoidCategory<T>::pow(NonNegative<int> n) {
  return MonoidCommon<T, MonoidCategory<T> >::repeatedComposition((T&) *this, n);
}

#endif


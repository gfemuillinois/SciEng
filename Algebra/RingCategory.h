/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RingCategoryH
#define RingCategoryH

#include "Algebra/SemiGroupCategory.h"
#include "Algebra/AbelianGroupCategory.h"


template<class T>
class RingCategory : 
    public AbelianGroupCategory<T>, 
    public SemiGroupCategory<T> {
};


#endif


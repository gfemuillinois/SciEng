/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef EquivalentCategoryH
#define EquivalentCategoryH

#include "SciEng/Boolean.h"

//namespace SciEngLib{

template<class DerivedType>
class EquivalentCategory {
    // This class needed for type restriction
  // User Must Define: Boolean equivalentTo(const AnArray& rhs);
    friend Boolean operator==(const DerivedType& lhs, const DerivedType& rhs) {
        return lhs.equivalentTo(rhs);
    }
    friend Boolean operator!=(const DerivedType& lhs, const DerivedType& rhs) {
        return ! lhs.equivalentTo(rhs);
    }
};

//}

#endif

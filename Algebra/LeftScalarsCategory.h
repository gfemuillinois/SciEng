/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LeftScalarsCategoryH
#define LeftScalarsCategoryH

#include "Algebra/FieldScalarsCategory.h"
#include "Algebra/GroupCategory.h"


template<class V, class S>
class LeftScalarsCategory :  
    public FieldScalarsCategory<V,S> {
    public:
    friend V operator/(const S& s, const V& v) { V temp(inverse(v)); return temp *= s; }
};

#endif

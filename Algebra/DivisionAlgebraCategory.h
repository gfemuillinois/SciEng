/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DivisionAlgebraCategoryH
#define DivisionAlgebraCategoryH

#include "Algebra/LeftScalarsCategory.h"
#include "Algebra/FieldCategory.h"


template<class V, class S>
class DivisionAlgebraCategory : 
    public FieldCategory<V>,
    public LeftScalarsCategory<V,S> {
};

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LinearAlgebraCategoryH
#define LinearAlgebraCategoryH

#include "Algebra/RingCategory.h"
#include "Algebra/LeftScalarsCategory.h"

template<class V, class S>
class LinearAlgebraCategory :
  public RingCategory<V>,
  public FieldScalarsCategory<V,S> {
};

#endif

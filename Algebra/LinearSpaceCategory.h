/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LinearSpaceCategoryH
#define LinearSpaceCategoryH

#include "Algebra/FieldScalarsCategory.h"
#include "Algebra/AbelianGroupCategory.h"

template<class V, class S>
class LinearSpaceCategory :
  public AbelianGroupCategory<V>,
  public FieldScalarsCategory<V,S> {
};
#endif

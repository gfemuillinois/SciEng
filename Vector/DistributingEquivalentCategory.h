/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingEquivalentCategoryH
#define DistributingEquivalentCategoryH

#include "SciEng/EquivalentCategory.h"

template<class AnArray>
class DistributingEquivalentCategory :
  public EquivalentCategory<AnArray> {
public:
  Boolean equivalentTo(const AnArray& rhs) const;
};

#ifdef XLC_QNOTEMPINC
#include "Vector/DistributingEquivalentCategory.c"
#endif

#endif

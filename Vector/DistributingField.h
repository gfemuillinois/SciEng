/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingFieldH
#define DistributingFieldH

#include "Vector/DistributingAbelianGroup.h"
#include "Vector/DistributingGroup.h"

template<class Array, class T>
class DistributingField :
  public DistributingGroup<Array, T>,
  public DistributingAbelianGroup<Array, T> {
};

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingRingH
#define DistributingRingH

#include "Vector/DistributingAbelianGroup.h"
#include "Vector/DistributingSemiGroup.h"

template<class Array, class T>
class DistributingRing :
  public DistributingSemiGroup<Array, T>,
  public DistributingAbelianGroup<Array, T> {
};
      
#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingAlgebraWithUnitH
#define DistributingAlgebraWithUnitH

#include "Vector/DistributingRingWithUnit.h"
#include "Vector/DistributingFieldScalars.h"

template<class Array, class T, class S>
class DistributingAlgebraWithUnit :
  public DistributingRingWithUnit<Array, T>,
  public DistributingFieldScalars<Array, T, S> {
public:
  Array& operator*=(const Array& rhs) { return DistributingRingWithUnit<Array, T>::operator*=(rhs); }
  Array& operator/=(const Array& rhs) { return DistributingRingWithUnit<Array, T>::operator/=(rhs); }
  Array& operator*=(const S& rhs) { return DistributingFieldScalars<Array, T, S>::operator*=(rhs); }
  Array& operator/=(const S& rhs) { return DistributingFieldScalars<Array, T, S>::operator/=(rhs); }
};

#endif

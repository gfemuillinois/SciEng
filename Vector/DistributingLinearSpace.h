/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingLinearSpaceH
#define DistributingLinearSpaceH

#include "Vector/DistributingAbelianGroup.h"
#include "Vector/DistributingFieldScalars.h"


template<class Array, class T, class S>
class DistributingLinearSpace :             
  public DistributingAbelianGroup<Array, T>,
  public DistributingFieldScalars<Array, T, S> {

public:

  // CAD
  Array& operator+=(const Array& rhs) { 
    return DistributingAbelianSemiGroup<Array, T>::operator+=(rhs); }
  // CAD
  Array& operator-=(const Array& rhs) { 
    return DistributingAbelianGroup<Array, T>::operator-=(rhs); }
  // CAD
  Array& operator+=(const S& rhs) {
    return DistributingExternalScalars<Array, T, S>::operator+=(rhs); }
  // CAD
  Array& operator-=(const S& rhs) {
    return DistributingFieldScalars<Array, T, S>::operator-=(rhs); }
};


#endif

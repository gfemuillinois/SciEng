/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingDivisionAlgebraH
#define DistributingDivisionAlgebraH

#include "Vector/DistributingField.h"
#include "Vector/DistributingLeftScalars.h"


template<class Array, class T, class S>
class DistributingDivisionAlgebra :             
    public DistributingField<Array, T>,
    public DistributingLeftScalars<Array, T, S> {
public:

   Array& operator*=(const Array& rhs) { 
      return DistributingField<Array, T>::operator*=(rhs); }
    Array& operator/=(const Array& rhs) { 
      return DistributingField<Array, T>::operator/=(rhs); }

    Array& operator*=(const S& rhs)     { 
      return DistributingLeftScalars<Array, T, S>::operator*=(rhs); }
    Array& operator/=(const S& rhs)     { 
      return DistributingLeftScalars<Array, T, S>::operator/=(rhs); }

  // CAD
  Array& operator+=(const Array& rhs) { 
    return DistributingField<Array, T>::operator+=(rhs); }
  // CAD
  Array& operator-=(const Array& rhs) { 
    return DistributingField<Array, T>::operator-=(rhs); }

  // CAD
  Array& operator+=(const S& rhs) {
    return DistributingLeftScalars<Array, T, S>::operator+=(rhs); }
  // CAD
  Array& operator-=(const S& rhs) {
    return DistributingLeftScalars<Array, T, S>::operator-=(rhs); }
};


#endif

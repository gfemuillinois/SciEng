/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingFieldScalarsH
#define DistributingFieldScalarsH

#include "Vector/DistributingExternalScalars.h"

template<class Array, class T, class S>
class DistributingFieldScalars :
  public DistributingExternalScalars<Array, T, S> {
public:
  Array& operator/=(const S& rhs) { return DistributeS<Div,Array,T>::over((Array&) *this, rhs); }
private:
  class Div { public: Div(T& lhs, const S& rhs) { lhs /= rhs; } };
};

#endif

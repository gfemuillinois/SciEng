/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingExternalScalarsH
#define DistributingExternalScalarsH

#include "Vector/Distribute.h"

template<class Array, class T, class S>
class DistributingExternalScalars {
public:
  Array& operator*=(const S& rhs) { return DistributeS<Mult,Array,T>::over((Array&) *this, rhs); }
private:
  class Mult { public: Mult(T& lhs, const S& rhs) { lhs *= rhs; } };
};

#endif

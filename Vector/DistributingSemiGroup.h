/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingSemiGroupH
#define DistributingSemiGroupH

#include "Vector/Distribute.h"

template<class Array, class T>
class DistributingSemiGroup {
public:
  Array& operator*=(const Array& rhs) { return Distribute2<Mult,Array>::over((Array&) *this, rhs); }
private:
  class Mult { public: Mult(T& lhs, const T& rhs) { lhs *= rhs; } };
};

#endif

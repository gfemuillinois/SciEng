/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingAbelianGroupH
#define DistributingAbelianGroupH

#include "Vector/DistributingAbelianMonoid.h"


template<class Array, class T>
class DistributingAbelianGroup : 
    public DistributingAbelianMonoid<Array, T> {
public:
    Array& operator-=(const Array& rhs) { return Distribute2<Sub,Array>::over((Array&) *this, rhs); }
private:
    class Sub { public: Sub(T& lhs, const T& rhs) { lhs -= rhs; } };
};


#endif

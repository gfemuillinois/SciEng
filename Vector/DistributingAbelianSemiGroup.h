/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingAbelianSemiGroupH
#define DistributingAbelianSemiGroupH

#include "Vector/Distribute.h"


template<class Array, class T>
class DistributingAbelianSemiGroup {             
public:
    Array& operator+=(const Array& rhs) { return Distribute2<Add,Array>::over((Array&) *this, rhs); }
private:
    class Add { public: Add(T& lhs, const T& rhs) { lhs += rhs; } };
};


#endif

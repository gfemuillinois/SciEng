/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingLinearAlgebraH
#define DistributingLinearAlgebraH

#include "Vector/DistributingRing.h"
#include "Vector/DistributingFieldScalars.h"


template<class Array, class T, class S>
class DistributingLinearAlgebra :             
    public DistributingRing<Array, T>,
    public DistributingFieldScalars<Array, T, S> {
public:

    Array& operator*=(const Array& rhs) { return DistributingRing<Array, T>::operator*=(rhs); }
    Array& operator*=(const S& rhs)     { return DistributingFieldScalars<Array, T, S>::operator*=(rhs); }

};


#endif

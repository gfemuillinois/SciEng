/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AXPYH
#define AXPYH
#include "Array/ConcreteFormedArray1d.h"

#define Vector ConcreteFormedArray1d


template<class EltType> 
extern void axpy(EltType alpha, const Vector<EltType>& x, Vector<EltType>& y);


#ifdef XLC_QNOTEMPINC
#include "examples/ch5/axpy.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFortranArray2dH
#define ConcreteFortranArray2dH

#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray2d.h"


template<class T>
class ConcreteFortranArray2d :              
    public ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T > {
public:
    ConcreteFortranArray2d(Subscript s0, Subscript s1);
    ConcreteFortranArray2d(const ConcreteFortranArray2d<T>& p);
    ConcreteFortranArray2d(const ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<2>, T>&);
    ConcreteFortranArray2d(const ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<3>::ProjectionT, T>&);
    ConcreteFortranArray2d(const ConstArray2d<T>&);

    ~ConcreteFortranArray2d();

    ConcreteFortranArray2d<T>& operator=(const ConcreteFortranArray2d<T>& rhs);
    ConcreteFortranArray2d<T>& operator=(const ConcreteArray2dConstRef<SubscriptorT, T>& rhs);
    ConcreteFortranArray2d<T>& operator=(const T& rhs);

    void reshape(const SubscriptArray<2>& s) { reshapeOnHeap(s); }
};


#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFortranArray2d.c"
#endif

#endif

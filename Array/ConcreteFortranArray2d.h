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
  typedef ConcreteColumnMajorSubscriptor<2> SubscriptorType;

    ConcreteFortranArray2d();  // For arrays of arrays.
    ConcreteFortranArray2d(Subscript s0, Subscript s1);
    // copy constructor provides deep copy
    ConcreteFortranArray2d(const ConcreteFortranArray2d<T>& p);
    ConcreteFortranArray2d(const ConcreteArray2dConstRef< SubscriptorType, T>&);
    ConcreteFortranArray2d(const ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<3>::ProjectionT, T>&);
    ConcreteFortranArray2d(const ConstArray2d<T>&);

    ~ConcreteFortranArray2d();

    ConcreteFortranArray2d<T>& operator=(const ConcreteFortranArray2d<T>& rhs);
    ConcreteFortranArray2d<T>& operator=(const ConcreteArray2dConstRef<SubscriptorType, T>& rhs);
    ConcreteFortranArray2d<T>& operator=(const T& rhs);

    void reshape(const SubscriptArray<2>& s) { reshapeOnHeap(s); }

    void clear() { reshape( SubscriptArray<2>(0, 0) ); }

protected:
  using ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T >::reshapeOnHeap;
  using ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T >::setSizeOnHeap;
  using ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T >::datap;

};


#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFortranArray2d.c"
#endif

#endif

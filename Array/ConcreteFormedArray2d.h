/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFormedArray2dH
#define ConcreteFormedArray2dH

#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray2d.h"


template<class T>
class ConcreteFormedArray2d :
  public ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T > {
public:
  ConcreteFormedArray2d();  // For arrays of arrays.
  ConcreteFormedArray2d(Subscript s0, Subscript s1);
  // copy constructor provides deep copy
  ConcreteFormedArray2d(const ConcreteFormedArray2d<T>&);

  ConcreteFormedArray2d(const ConcreteArray2dConstRef<ConcreteRowMajorSubscriptor<2>, T>&);
  ConcreteFormedArray2d(const ConcreteArray2dConstRef< typename ConcreteRowMajorSubscriptor<3>::ProjectionT, T>&);

  ~ConcreteFormedArray2d();

  ConcreteFormedArray2d<T>& operator=(const ConcreteFormedArray2d<T>& rhs);
  ConcreteFormedArray2d<T>& operator=(const ConcreteArray2dConstRef< typename ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>& rhs);
  ConcreteFormedArray2d<T>& operator=(const T& rhs);
  
  void reshape(const SubscriptArray<2>& s) { reshapeOnHeap(s); }

protected:
  ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T >::reshapeOnHeap;
  ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T >::setSizeOnHeap;

  ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T >::datap;
};

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFormedArray2d.c"
#endif

#endif

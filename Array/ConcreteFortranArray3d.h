/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFortranArray3dH
#define ConcreteFortranArray3dH

#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray3d.h"


template<class T>
class ConcreteFortranArray3d :
  public ConcreteArray3d<ConcreteColumnMajorSubscriptor<3>, T > {
public:
  typedef ConcreteColumnMajorSubscriptor<3> SubscriptorType;

  ConcreteFortranArray3d(Subscript s0, Subscript s1, Subscript s2);
  ConcreteFortranArray3d(const ConcreteFortranArray3d<T>& p);
  ConcreteFortranArray3d(const ConcreteArray3dConstRef<ConcreteColumnMajorSubscriptor<3>, T>&);
  ConcreteFortranArray3d(const ConcreteArray3dConstRef<ConcreteColumnMajorSubscriptor<4>::ProjectionT, T>&);

  ~ConcreteFortranArray3d();

  ConcreteFortranArray3d<T>& operator=(const ConcreteFortranArray3d<T>& rhs);
  ConcreteFortranArray3d<T>& operator=(const ConcreteArray3dConstRef<SubscriptorType, T>& rhs);
  ConcreteFortranArray3d<T>& operator=(const T& rhs);
  
  void reshape(const SubscriptArray<3>& s) { reshapeOnHeap(s); }
};

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFortranArray3d.c"
#endif

#endif

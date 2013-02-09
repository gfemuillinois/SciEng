/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFormedArray3dH
#define ConcreteFormedArray3dH

#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray3d.h"


template<class T>
class ConcreteFormedArray3d :
  public ConcreteArray3d<ConcreteRowMajorSubscriptor<3>, T > {
public:
  typedef ConcreteRowMajorSubscriptor<3> SubscriptorType;

  ConcreteFormedArray3d();
  ConcreteFormedArray3d(Subscript s0, Subscript s1, Subscript s2);
  ConcreteFormedArray3d(const ConcreteFormedArray3d<T>& p);
  ConcreteFormedArray3d(const ConcreteArray3dConstRef<ConcreteRowMajorSubscriptor<3>, T>&);
  ConcreteFormedArray3d(const ConcreteArray3dConstRef<ConcreteRowMajorSubscriptor<4>::ProjectionT, T>&);

  ~ConcreteFormedArray3d();

  ConcreteFormedArray3d<T>& operator=(const ConcreteFormedArray3d<T>& rhs);
  ConcreteFormedArray3d<T>& operator=(const ConcreteArray3dConstRef<SubscriptorType, T>& rhs);
  ConcreteFormedArray3d<T>& operator=(const T& rhs);
  
  void reshape(const SubscriptArray<3>& s) { reshapeOnHeap(s); }

protected:

  using ConcreteArray3d<ConcreteRowMajorSubscriptor<3>, T >::reshapeOnHeap;
  using ConcreteArray3d<ConcreteRowMajorSubscriptor<3>, T >::setSizeOnHeap;
  using ConcreteArray3d<ConcreteRowMajorSubscriptor<3>, T >::datap;

};

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFormedArray3d.c"
#endif

#endif

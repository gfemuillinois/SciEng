/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFormedArray1dH
#define ConcreteFormedArray1dH


#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray1d.h"
      
//namespace SciEngLib {

template<class T>
class ConcreteFormedArray1d :
  public ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, T> {
public:
  typedef ConcreteRowMajorSubscriptor<1> SubscriptorType;
  
  ConcreteFormedArray1d();
  explicit ConcreteFormedArray1d(Subscript s0);
  ConcreteFormedArray1d(const ConcreteFormedArray1d<T>&);
  ConcreteFormedArray1d(ConcreteArray1dConstRef<SubscriptorType, T>);
  ConcreteFormedArray1d(ConcreteArray1dConstRef<ConcreteRowMajorSubscriptor<2>::ProjectionT, T>);

  ~ConcreteFormedArray1d();

  ConcreteFormedArray1d<T>& operator=(const ConcreteFormedArray1d<T>& rhs);
  ConcreteFormedArray1d<T>& operator=(ConcreteArray1dConstRef<SubscriptorType, T> rhs);
  ConcreteFormedArray1d<T>& operator=(const T& rhs);
  
  void reshape(const Subscript s) { 
    reshapeOnHeap( s ); }

  void clear() { reshape(0); }
};

//}

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFormedArray1d.c"
#endif

#endif

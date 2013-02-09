/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFortranArray1dH
#define ConcreteFortranArray1dH


#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray1d.h"
      
template<class T>
class ConcreteFortranArray1d :
  public ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T> {
public:
  typedef ConcreteColumnMajorSubscriptor<1> Subscriptor;
  
  explicit ConcreteFortranArray1d(Subscript s0);
  ConcreteFortranArray1d(const ConcreteFortranArray1d<T>&);
  ConcreteFortranArray1d(ConcreteArray1dConstRef<Subscriptor, T>);
  ConcreteFortranArray1d(ConcreteArray1dConstRef<ConcreteColumnMajorSubscriptor<2>::ProjectionT, T>);

  ~ConcreteFortranArray1d();

  ConcreteFortranArray1d<T>& operator=(const ConcreteFortranArray1d<T>& rhs);
  ConcreteFortranArray1d<T>& operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs);
  ConcreteFortranArray1d<T>& operator=(const T& rhs);
  
  void reshape(const Subscript s) { reshapeOnHeap(s); }

protected:
  using ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::reshapeOnHeap;
  using ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::setSizeOnHeap;
  using ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::datap;

};

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFortranArray1d.c"
#endif

#endif

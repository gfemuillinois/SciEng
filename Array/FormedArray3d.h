/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedArray3dH
#define FormedArray3dH

#include "Array/ConcreteFormedArray3d.h"
#include "Array/InterfacedArray3d.h"

template<class T>
class FormedArray3d :
  public InterfacedArray3d< ConcreteFormedArray3d<T> > {
public:
  FormedArray3d(Subscript n0, Subscript n1, Subscript n2) : 
    InterfacedArray3d< ConcreteFormedArray3d<T> >(n0, n1, n2) {}
  FormedArray3d(const ConstArray3d<T>& a) : InterfacedArray3d< ConcreteFormedArray3d<T> >(a) {}

  virtual void reshape(const SubscriptArray<3>& s)     { the_concrete.reshape(s); }

  virtual Array3d<T>& operator=(const ConstArray3d<T>& rhs) {
    return InterfacedArray3d< ConcreteFormedArray3d<T> >::operator=(rhs);
  }
  virtual Array3d<T>& operator=(const T& rhs) {
    return InterfacedArray3d< ConcreteFormedArray3d<T> >::operator=(rhs);
  }
  
  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }

protected:
  InterfacedArray3d< ConcreteFormedArray3d<T> >::the_concrete;
};

#endif

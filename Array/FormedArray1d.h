/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedArray1dH
#define FormedArray1dH

#include "Array/InterfacedArray1d.h"
#include "Array/ConcreteFormedArray1d.h"

template<class T>
class FormedArray1d :
  public InterfacedArray1d< ConcreteFormedArray1d<T> > {
public:
  FormedArray1d(Subscript n)              : InterfacedArray1d< ConcreteFormedArray1d<T> >(n) {}
  FormedArray1d(const ConstArray1d<T>& a) : InterfacedArray1d< ConcreteFormedArray1d<T> >(a) {}
  
  virtual void reshape(const SubscriptArray<1>& s)     { 
    the_concrete.reshape( s(0) ); }

  virtual Array1d<T>& operator=(const ConstArray1d<T>& rhs) {
    return InterfacedArray1d< ConcreteFormedArray1d<T> >::operator=(rhs);
  }
  virtual Array1d<T>& operator=(const T& rhs) {
    return InterfacedArray1d< ConcreteFormedArray1d<T> >::operator=(rhs);
  }
  
  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }
};

#endif

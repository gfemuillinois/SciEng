/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FortranArray1dH
#define FortranArray1dH

#include "Array/InterfacedArray1d.h"
#include "Array/ConcreteFortranArray1d.h"

template<class T>
class FortranArray1d :
  public InterfacedArray1d< ConcreteFortranArray1d<T> > {
public:
  FortranArray1d(Subscript n)              : InterfacedArray1d< ConcreteFortranArray1d<T> >(n) {}
  FortranArray1d(const ConstArray1d<T>& a) : InterfacedArray1d< ConcreteFortranArray1d<T> >(a) {}
  
  virtual void reshape(const SubscriptArray<1>& s)     { the_concrete.reshape(s); }

  virtual Array1d<T>& operator=(const ConstArray1d<T>& rhs) {
    return InterfacedArray1d< ConcreteFortranArray1d<T> >::operator=(rhs);
  }
  virtual Array1d<T>& operator=(const T& rhs) {
    return InterfacedArray1d< ConcreteFortranArray1d<T> >::operator=(rhs);
  }
  
  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }
};

#endif

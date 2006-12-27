/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FortranArray2dH
#define FortranArray2dH

#include "Array/ConcreteFortranArray2d.h"
#include "Array/InterfacedArray2d.h"

template<class T>
class FortranArray2d :
  public InterfacedArray2d< ConcreteFortranArray2d<T> > {
public:
  FortranArray2d(Subscript n0, Subscript n1) : InterfacedArray2d< ConcreteFortranArray2d<T> >(n0, n1) {}
  FortranArray2d(const ConstArray2d<T>& a) :   InterfacedArray2d< ConcreteFortranArray2d<T> >(a) {}

  virtual void reshape(const SubscriptArray<2>& s)     { the_concrete.reshape(s); }

  virtual Array2d<T>& operator=(const ConstArray2d<T>& rhs) {
    return InterfacedArray2d< ConcreteFortranArray2d<T> >::operator=(rhs);
  }
  virtual Array2d<T>& operator=(const T& rhs) {
    return InterfacedArray2d< ConcreteFortranArray2d<T> >::operator=(rhs);
  }

  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }

protected:
  InterfacedArray2d< ConcreteFortranArray2d<T> >::the_concrete;
};

#endif

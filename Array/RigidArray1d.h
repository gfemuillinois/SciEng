/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidArray1dH
#define RigidArray1dH

#include "Array/InterfacedArray1d.h"
#include "Array/ConcreteRigidArray1d.h"

class ostream;

template<class T, Subscript n0>
class RigidArray1d :
  public InterfacedArray1d< ConcreteRigidArray1d<T, n0> > {
public:
  RigidArray1d()              : InterfacedArray1d< ConcreteRigidArray1d<T, n0> >(n0) {}
  RigidArray1d(Subscript n)              : InterfacedArray1d< ConcreteRigidArray1d<T, n0> >(n) {}
  RigidArray1d(const ConstArray1d<T>& a) : InterfacedArray1d< ConcreteRigidArray1d<T, n0> >(a) {}

  virtual Array1d<T>& operator=(const ConstArray1d<T>& rhs) {
    return InterfacedArray1d< ConcreteRigidArray1d<T, n0> >::operator=(rhs);
  }
  virtual Array1d<T>& operator=(const T& rhs) {
    return InterfacedArray1d< ConcreteRigidArray1d<T, n0> >::operator=(rhs);
  }
  
  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }
};

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidArray2dH
#define RigidArray2dH

#include "Array/ConcreteRigidArray2d.h"
#include "Array/InterfacedArray2d.h"

class ostream;

template<class T, Subscript n0, Subscript n1>
class RigidArray2d :
  public InterfacedArray2d< ConcreteRigidArray2d<T, n0, n1> > {
public:
  RigidArray2d() : InterfacedArray2d< ConcreteRigidArray2d<T, n0, n1> >(n0, n1) {}
  RigidArray2d(Subscript s0, Subscript s1) : InterfacedArray2d< ConcreteRigidArray2d<T, n0, n1> >(s0, s1) {}
  RigidArray2d(const ConstArray2d<T>& a) :   InterfacedArray2d< ConcreteRigidArray2d<T, n0, n1> >(a) {}

  virtual Array2d<T>& operator=(const ConstArray2d<T>& rhs) {
    return InterfacedArray2d< ConcreteRigidArray2d<T, n0, n1> >::operator=(rhs);
  }
  virtual Array2d<T>& operator=(const T& rhs) {
    return InterfacedArray2d< ConcreteRigidArray2d<T, n0, n1> >::operator=(rhs);
  }

  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }
};

#endif

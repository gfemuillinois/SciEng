/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidArray3dH
#define RigidArray3dH

#include "Array/ConcreteRigidArray3d.h"
#include "Array/InterfacedArray3d.h"

#include<iosfwd>

template<class T, Subscript n0, Subscript n1, Subscript n2>
class RigidArray3d :
  public InterfacedArray3d< ConcreteRigidArray3d<T, n0, n1, n2> > {
public:
  RigidArray3d() : 
    InterfacedArray3d< ConcreteRigidArray3d<T, n0, n1, n2> >(n0, n1, n2) {}
  RigidArray3d(Subscript s0, Subscript s1, Subscript s2) : 
    InterfacedArray3d< ConcreteRigidArray3d<T, n0, n1, n2> >(s0, s1, s2) {}
  RigidArray3d(const ConstArray3d<T>& a) : InterfacedArray3d< ConcreteRigidArray3d<T, n0, n1, n2> >(a) {}

  virtual Array3d<T>& operator=(const ConstArray3d<T>& rhs) {
    return InterfacedArray3d< ConcreteRigidArray3d<T, n0, n1, n2> >::operator=(rhs);
  }
  virtual Array3d<T>& operator=(const T& rhs) {
    return InterfacedArray3d< ConcreteRigidArray3d<T, n0, n1, n2> >::operator=(rhs);
  }
  
  virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
  virtual       T* firstDatum()       { return the_concrete.firstDatum(); }
};

#endif

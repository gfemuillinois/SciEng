/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef InterfacedArray1dH
#define InterfacedArray1dH

#include "Array/Array1d.h"

template<class ConcreteArray1d>
class InterfacedArray1d :
  public virtual Array1d<ConcreteArray1d::EltT> {
public:

  InterfacedArray1d(Subscript s0) : the_concrete(s0) {}
  InterfacedArray1d(const ConstArray1d<EltT>& a) : the_concrete(a.shape(0)) { *this = a; }
  InterfacedArray1d(const ConcreteArray1d& a) : the_concrete(a) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }
  
  virtual const EltT&       operator()(Subscript i) const { return the_concrete(i); }
  virtual       EltT&       operator()(Subscript i)       { return the_concrete(i); }
  
  virtual const EltT&       project(Subscript i) const { return the_concrete[i]; }
  virtual       EltT&       project(Subscript i)       { return the_concrete[i]; }

  virtual Array1d<EltT>& operator=(const ConstArray1d<EltT>& rhs) { 
    return Array1d<ConcreteArray1d::EltT>::operator=(rhs);
  }
  virtual Array1d<EltT>& operator=(const EltT& rhs) {
    the_concrete = rhs;
    return *this;
  }

 protected:
  ConcreteArray1d the_concrete;
};

#endif

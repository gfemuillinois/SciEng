/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef InterfacedArray3dH
#define InterfacedArray3dH

#include "Array/Array2d.h"
#include "Array/Array3d.h"

template<class ConstConcreteArray3d>
class InterfacedConstArrayProjection2d :
  public ConstArray2d<ConstConcreteArray3d::EltT> {
public:
  InterfacedConstArrayProjection2d(const ConstConcreteArray3d::ConstProjectionT& a) : 
     the_concrete(a.subscriptor(), a.firstDatum()) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }
  virtual ConstProjectionT  project(Subscript i, Dimension d = 0) const { 
    return new InterfacedConstArrayProjection1d<ConstConcreteArray3d::ConstProjectionT>(the_concrete.project(i,d));
  }
  virtual const EltT&       operator()(Subscript i, Subscript j) const { return the_concrete(i, j); }

 protected:
  const ConstConcreteArray3d::ConstProjectionT the_concrete;
};

template<class ConcreteArray3d>
class InterfacedArrayProjection2d :
  public Array2d<ConcreteArray3d::EltT> {
public:
  InterfacedArrayProjection2d(const ConcreteArray3d::ProjectionT& a) : 
     the_concrete(a.subscriptor(), a.firstDatum()) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }
  
  virtual const EltT&       operator()(Subscript i, Subscript j) const { return the_concrete(i, j); }
  virtual       EltT&       operator()(Subscript i, Subscript j)       { return the_concrete(i, j); }
  virtual ConstProjectionT  project(Subscript i, Dimension d = 0) const {
    return new InterfacedConstArrayProjection1d<ConcreteArray3d::ConstProjectionT>(the_concrete.project(i, d));
  }
  virtual ProjectionT  project(Subscript i, Dimension d = 0) { 
    return new InterfacedArrayProjection1d<ConcreteArray3d::ProjectionT>(the_concrete.project(i,d));
  }
   
  virtual Array2d<EltT>& operator=(const ConstArray2d<EltT>& rhs) { 
    return Array2d<ConcreteArray3d::EltT>::operator=(rhs);
  }
  virtual Array2d<EltT>& operator=(const EltT& rhs) { 
    the_concrete = rhs;
    return *this;
  }
protected:
  ConcreteArray3d::ProjectionT the_concrete;
};

template<class ConcreteArray3d>
class InterfacedArray3d :
  public virtual Array3d<ConcreteArray3d::EltT> {
public:

  InterfacedArray3d(Subscript s0, Subscript s1, Subscript s2) : the_concrete(s0, s1, s2) {}
  InterfacedArray3d(const ConstArray3d<EltT>& a) : the_concrete(a.shape(0), a.shape(1), a.shape(2)) { *this = a; }
  InterfacedArray3d(const ConcreteArray3d& a) : the_concrete(a) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts();  }
  
  virtual const EltT&       operator()(Subscript i, Subscript j, Subscript k) const { return the_concrete(i,j,k); }
  virtual       EltT&       operator()(Subscript i, Subscript j, Subscript k)       { return the_concrete(i,j,k); }
  
  virtual ConstProjectionT   project(Subscript i, Dimension d = 0) const { 
    return new InterfacedConstArrayProjection2d<ConcreteArray3d>(the_concrete.project(i,d));
  }
  virtual ProjectionT        project(Subscript i, Dimension d = 0)       { 
    return new InterfacedArrayProjection2d<ConcreteArray3d>(the_concrete.project(i,d));
  }
   
  virtual Array3d<EltT>& operator=(const ConstArray3d<EltT>& rhs) { 
    return Array3d<ConcreteArray3d::EltT>::operator=(rhs);
  }
  virtual Array3d<EltT>& operator=(const EltT& rhs) {
    the_concrete = rhs;
    return *this;
  }
 
protected:
  ConcreteArray3d the_concrete;
};

#endif

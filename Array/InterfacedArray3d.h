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
  public ConstArray2d< typename ConstConcreteArray3d::EltT> {
public:
  InterfacedConstArrayProjection2d(const typename ConstConcreteArray3d::ConstProjectionT& a) : 
     the_concrete(a.subscriptor(), a.firstDatum()) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }

  virtual typename ConstArray2d< typename ConstConcreteArray3d::EltT>::ConstProjectionT 
    project(Subscript i, Dimension d = 0) const { 
    return new InterfacedConstArrayProjection1d< typename ConstConcreteArray3d::ConstProjectionT>
      (the_concrete.project(i,d));
  }
  virtual const typename ConstConcreteArray3d::EltT&  
    operator()(Subscript i, Subscript j) const { return the_concrete(i, j); }

 protected:
  const typename ConstConcreteArray3d::ConstProjectionT the_concrete;
};

template<class ConcreteArray3d>
class InterfacedArrayProjection2d :
  public Array2d< typename ConcreteArray3d::EltT> {
public:
  InterfacedArrayProjection2d(const typename ConcreteArray3d::ProjectionT& a) : 
     the_concrete(a.subscriptor(), a.firstDatum()) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }
  
  virtual const typename ConcreteArray3d::EltT& 
    operator()(Subscript i, Subscript j) const { return the_concrete(i, j); }
  virtual       typename ConcreteArray3d::EltT&
    operator()(Subscript i, Subscript j)       { return the_concrete(i, j); }

  virtual typename ConstArray2d< typename ConcreteArray3d::EltT>::ConstProjectionT
    project(Subscript i, Dimension d = 0) const {
    return new InterfacedConstArrayProjection1d< typename ConcreteArray3d::ConstProjectionT>
      (the_concrete.project(i, d));
  }
  virtual typename Array2d< typename ConcreteArray3d::EltT>::ProjectionT
    project(Subscript i, Dimension d = 0) { 
    return new InterfacedArrayProjection1d< typename ConcreteArray3d::ProjectionT>
      (the_concrete.project(i,d));
  }
   
  virtual Array2d<typename ConcreteArray3d::EltT>&
    operator=(const ConstArray2d< typename ConcreteArray3d::EltT>& rhs) { 
      return Array2d<typename ConcreteArray3d::EltT>::operator=(rhs);
    }
  virtual Array2d<typename ConcreteArray3d::EltT>&
    operator=(const typename ConcreteArray3d::EltT& rhs) { 
      the_concrete = rhs;
      return *this;
    }
protected:
  typename ConcreteArray3d::ProjectionT the_concrete;
};

template<class ConcreteArray3d>
class InterfacedArray3d :
  public virtual Array3d< typename ConcreteArray3d::EltT> {
public:

  InterfacedArray3d(Subscript s0, Subscript s1, Subscript s2) : the_concrete(s0, s1, s2) {}
  InterfacedArray3d(const ConstArray3d<typename ConcreteArray3d::EltT>& a) 
    : the_concrete(a.shape(0), a.shape(1), a.shape(2)) { *this = a; }
  InterfacedArray3d(const ConcreteArray3d& a) : the_concrete(a) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts();  }
  
  virtual const typename ConcreteArray3d::EltT&
    operator()(Subscript i, Subscript j, Subscript k) const { return the_concrete(i,j,k); }
  virtual       typename ConcreteArray3d::EltT& 
    operator()(Subscript i, Subscript j, Subscript k)       { return the_concrete(i,j,k); }
  
  virtual typename ConstArray3d< typename ConcreteArray3d::EltT>::ConstProjectionT
    project(Subscript i, Dimension d = 0) const { 
    return new InterfacedConstArrayProjection2d<ConcreteArray3d>(the_concrete.project(i,d));
  }
  virtual typename Array3d< typename ConcreteArray3d::EltT>::ProjectionT
    project(Subscript i, Dimension d = 0)       { 
    return new InterfacedArrayProjection2d<ConcreteArray3d>(the_concrete.project(i,d));
  }
   
  virtual Array3d<typename ConcreteArray3d::EltT>& 
    operator=(const ConstArray3d<typename ConcreteArray3d::EltT>& rhs) { 
      return Array3d<typename ConcreteArray3d::EltT>::operator=(rhs);
    }
  virtual Array3d<typename ConcreteArray3d::EltT>& 
    operator=(const typename ConcreteArray3d::EltT& rhs) {
      the_concrete = rhs;
      return *this;
    }
 
protected:
  ConcreteArray3d the_concrete;
};

#endif

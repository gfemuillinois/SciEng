/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef InterfacedArray2dH
#define InterfacedArray2dH

#include "Array/Array1d.h"
#include "Array/Array2d.h"

template<class ConcreteArray2d>
class InterfacedConstArrayProjection1d :
  public virtual ConstArray1d< typename ConcreteArray2d::EltT> {
public:
  InterfacedConstArrayProjection1d(const typename ConcreteArray2d::ConstProjectionT& a) : 
     the_concrete(a.subscriptor(), a.firstDatum()) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }
  
  virtual const typename ConcreteArray2d::EltT&   operator()(Subscript i) const { return the_concrete(i); }

 protected:
  const typename ConcreteArray2d::ConstProjectionT the_concrete;
};


template<class ConcreteArray2d>
class InterfacedArrayProjection1d :
    public virtual Array1d< typename ConcreteArray2d::EltT> {
public:
    InterfacedArrayProjection1d(const typename ConcreteArray2d::ProjectionT& a) :
        the_concrete(a.subscriptor(), a.firstDatum()) { 
    }


    virtual Subscript shape(Dimension d) const { return the_concrete.shape(d);  }
    virtual Subscript numElts()          const { return the_concrete.numElts(); }



    virtual const typename ConcreteArray2d::EltT& operator()(Subscript i) const { return the_concrete(i); }
    virtual       typename ConcreteArray2d::EltT& operator()(Subscript i)       { return the_concrete(i); }


    virtual Array1d<typename ConcreteArray2d::EltT>& 
      operator=(const ConstArray1d<typename ConcreteArray2d::EltT>& rhs) { 
        return Array1d<typename ConcreteArray2d::EltT>::operator=(rhs);
    }
    virtual Array1d<typename ConcreteArray2d::EltT>& 
      operator=(const typename ConcreteArray2d::EltT& rhs) {
        the_concrete = rhs;
        return *this;
    }
protected:
    typename ConcreteArray2d::ProjectionT the_concrete;
};



template<class ConcreteArray2d>
class InterfacedArray2d :              
    public virtual Array2d< typename ConcreteArray2d::EltT> {
public:

    InterfacedArray2d(Subscript s0, Subscript s1) : the_concrete(s0, s1) {}
    InterfacedArray2d(const ConstArray2d<typename ConcreteArray2d::EltT>& a) 
      : the_concrete(a.shape(0), a.shape(1)) { *this = a; }
    InterfacedArray2d(const ConcreteArray2d& a) : the_concrete(a) { }


    virtual Subscript         shape(Dimension d) const { return the_concrete.shape(d); }
    virtual Subscript         numElts()          const { return the_concrete.numElts();  }



    virtual const typename ConcreteArray2d::EltT& 
      operator()(Subscript i, Subscript j) const { return the_concrete(i, j); }
    virtual       typename ConcreteArray2d::EltT& 
      operator()(Subscript i, Subscript j)       { return the_concrete(i, j); }



    virtual typename ConstArray2d< typename ConcreteArray2d::EltT>::ConstProjectionT 
      project(Subscript i, Dimension d = 0) const;
    virtual typename Array2d< typename ConcreteArray2d::EltT>::ProjectionT
      project(Subscript i, Dimension d = 0);


    virtual Array2d<typename ConcreteArray2d::EltT>& 
      operator=(const ConstArray2d<typename ConcreteArray2d::EltT>& rhs) {
        return Array2d<typename ConcreteArray2d::EltT>::operator=(rhs);
    }
    virtual Array2d<typename ConcreteArray2d::EltT>& 
      operator=(const typename ConcreteArray2d::EltT& rhs) {
        the_concrete = rhs;
        return *this;
    }
protected:
    ConcreteArray2d the_concrete;
};


template<class ConcreteArray2d>
typename ConstArray2d< typename ConcreteArray2d::EltT>::ConstProjectionT  
InterfacedArray2d<ConcreteArray2d>::project(Subscript i, Dimension d) const {
    return new InterfacedConstArrayProjection1d<ConcreteArray2d>(the_concrete.project(i,d));
}


template<class ConcreteArray2d>
typename Array2d< typename ConcreteArray2d::EltT>::ProjectionT
InterfacedArray2d<ConcreteArray2d>::project(Subscript i, Dimension d) { 
    Array1d<typename ConcreteArray2d::EltT>* p =
        new InterfacedArrayProjection1d<ConcreteArray2d>(the_concrete.project(i, d));
    return AccessedArray1d<typename ConcreteArray2d::EltT>(p);
}

   
#endif

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
  public virtual ConstArray1d<ConcreteArray2d::EltT> {
public:
  InterfacedConstArrayProjection1d(const ConcreteArray2d::ConstProjectionT& a) : 
     the_concrete(a.subscriptor(), a.firstDatum()) { }

  virtual Subscript         shape(Dimension d)                const { return the_concrete.shape(d); }
  virtual Subscript         numElts()                         const { return the_concrete.numElts(); }
  
  virtual const EltT&       operator()(Subscript i) const { return the_concrete(i); }

 protected:
  const ConcreteArray2d::ConstProjectionT the_concrete;
};


template<class ConcreteArray2d>
class InterfacedArrayProjection1d :
    public virtual Array1d<ConcreteArray2d::EltT> {
public:
    InterfacedArrayProjection1d(const ConcreteArray2d::ProjectionT& a) :
        the_concrete(a.subscriptor(), a.firstDatum()) { 
    }


    virtual Subscript shape(Dimension d) const { return the_concrete.shape(d);  }
    virtual Subscript numElts()          const { return the_concrete.numElts(); }



    virtual const EltT& operator()(Subscript i) const { return the_concrete(i); }
    virtual       EltT& operator()(Subscript i)       { return the_concrete(i); }


    virtual Array1d<EltT>& operator=(const ConstArray1d<EltT>& rhs) { 
        return Array1d<ConcreteArray2d::EltT>::operator=(rhs);
    }
    virtual Array1d<EltT>& operator=(const EltT& rhs) {
        the_concrete = rhs;
        return *this;
    }
protected:
    ConcreteArray2d::ProjectionT the_concrete;
};



template<class ConcreteArray2d>
class InterfacedArray2d :              
    public virtual Array2d<ConcreteArray2d::EltT> {
public:

    InterfacedArray2d(Subscript s0, Subscript s1) : the_concrete(s0, s1) {}
    InterfacedArray2d(const ConstArray2d<EltT>& a) : the_concrete(a.shape(0), a.shape(1)) { *this = a; }
    InterfacedArray2d(const ConcreteArray2d& a) : the_concrete(a) { }


    virtual Subscript         shape(Dimension d) const { return the_concrete.shape(d); }
    virtual Subscript         numElts()          const { return the_concrete.numElts();  }



    virtual const EltT& operator()(Subscript i, Subscript j) const { return the_concrete(i, j); }
    virtual       EltT& operator()(Subscript i, Subscript j)       { return the_concrete(i, j); }



    virtual ConstProjectionT project(Subscript i, Dimension d = 0) const;
    virtual ProjectionT      project(Subscript i, Dimension d = 0);


    virtual Array2d<EltT>& operator=(const ConstArray2d<EltT>& rhs) {
        return Array2d<EltT>::operator=(rhs);
    }
    virtual Array2d<EltT>& operator=(const EltT& rhs) {
        the_concrete = rhs;
        return *this;
    }
protected:
    ConcreteArray2d the_concrete;
};


template<class ConcreteArray2d>
InterfacedArray2d<ConcreteArray2d>::ConstProjectionT  
InterfacedArray2d<ConcreteArray2d>::project(Subscript i, Dimension d) const {
    return new InterfacedConstArrayProjection1d<ConcreteArray2d>(the_concrete.project(i,d));
}


template<class ConcreteArray2d>
InterfacedArray2d<ConcreteArray2d>::ProjectionT
InterfacedArray2d<ConcreteArray2d>::project(Subscript i, Dimension d) { 
    Array1d<EltT>* p =
        new InterfacedArrayProjection1d<ConcreteArray2d>(the_concrete.project(i, d));
    return AccessedArray1d<EltT>(p);
}

   
#endif

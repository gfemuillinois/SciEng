/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef BinaryFunctionalH
#define BinaryFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class BinaryFunctional {      
public:
    BinaryFunctional( 
            const CloneableObjPtr<IsoFunctional<Domain> >& lhs,
            const CloneableObjPtr<IsoFunctional<Domain> >& rhs 
    ): 
        the_lhs(lhs),
        the_rhs(rhs) {
    }
    const IsoFunctional<Domain>& lhs() const { return *the_lhs; }
    const IsoFunctional<Domain>& rhs() const { return *the_rhs; }
private:
    CloneableObjPtr< IsoFunctional<Domain> > the_lhs;
    CloneableObjPtr< IsoFunctional<Domain> > the_rhs;
};



template<class Domain>
class AddFunctional :  
    public virtual IsoFunctional<Domain>,
    private BinaryFunctional<Domain> {
public:
    AddFunctional( 
            const CloneableObjPtr< IsoFunctional<Domain> >& lhs,
            const CloneableObjPtr< IsoFunctional<Domain> >& rhs 
    ):  
        BinaryFunctional<Domain>(lhs, rhs){
    }

    virtual Domain operator()(const Domain& v) const { return lhs()(v) + rhs()(v);}

    virtual AddFunctional<Domain>* clone() const { return new AddFunctional<Domain>(*this); }
};

    

template<class Domain>
class SubtractFunctional :
    public virtual IsoFunctional<Domain>,
    private BinaryFunctional<Domain> {
public:
    SubtractFunctional(
      const CloneableObjPtr< IsoFunctional<Domain> >& lhs,
      const CloneableObjPtr< IsoFunctional<Domain> >& rhs
    ):
      BinaryFunctional<Domain>(lhs,rhs){
    }
    virtual Domain operator()(const Domain& v) const {
       Domain s = lhs()(v);
       s -= rhs()(v);
       return s;
    }
    virtual SubtractFunctional<Domain>* clone() const { return new SubtractFunctional<Domain>(*this); }
};

template<class Domain>
class MultiplyFunctional :
    public virtual IsoFunctional<Domain>,
    private BinaryFunctional<Domain> {
public:
    MultiplyFunctional(
      const CloneableObjPtr< IsoFunctional<Domain> >& lhs,
      const CloneableObjPtr< IsoFunctional<Domain> >& rhs
    ):
      BinaryFunctional<Domain>(lhs,rhs){
    }
    
    MultiplyFunctional(const CloneableObjPtr< IsoFunctional<Domain> >& lhs, Domain rhs):
      BinaryFunctional<Domain>( lhs, new ConstantFunctional<Domain>(rhs) ) {
    }
    virtual Domain operator()(const Domain& v) const {
       Domain s = lhs()(v);
       s *= rhs()(v);
       return s;
    }
    virtual MultiplyFunctional<Domain>* clone() const { return new MultiplyFunctional<Domain>(*this); }
};

template<class Domain>
class DivideFunctional :
    public virtual IsoFunctional<Domain>,
    private BinaryFunctional<Domain> {
public:
    DivideFunctional(
      const CloneableObjPtr< IsoFunctional<Domain> >& lhs,
      const CloneableObjPtr< IsoFunctional<Domain> >& rhs
    ):
      BinaryFunctional<Domain>(lhs,rhs){
    }
    DivideFunctional(const CloneableObjPtr< IsoFunctional<Domain> >& lhs, Domain rhs):
      BinaryFunctional<Domain>( lhs, new ConstantFunctional<Domain>(rhs) ) {
    }
    virtual Domain operator()(const Domain& v) const {
       Domain s = lhs()(v);
       s /= rhs()(v);
       return s;
    }
    virtual DivideFunctional<Domain>* clone() const { return new DivideFunctional<Domain>(*this); }
};

#endif

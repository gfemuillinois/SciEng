/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef UnaryFunctionalH
#define UnaryFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"
#include "Algebra/BuiltinInverse.h"

template<class Domain>
class UnaryFunctional {
public:
    UnaryFunctional(const CloneableObjPtr< IsoFunctional<Domain> >& lhs):
      the_lhs(lhs){
    }
    const IsoFunctional<Domain>& lhs() const { return *the_lhs;}
private:
    CloneableObjPtr< IsoFunctional<Domain> > the_lhs;
};

template<class Domain>
class AdditiveInverseFunctional :
    public virtual IsoFunctional<Domain>,
    private UnaryFunctional<Domain> {
public:
    AdditiveInverseFunctional(const CloneableObjPtr<IsoFunctional<Domain> >& lhs):
      UnaryFunctional<Domain>(lhs){
    }
    virtual Domain operator()(const Domain& v) const {
       return -lhs()(v);
    }
    virtual AdditiveInverseFunctional<Domain>* clone() const {
      return new AdditiveInverseFunctional<Domain>(*this);
    }
};

template<class Domain>
class MultiplicativeInverseFunctional :
    public virtual IsoFunctional<Domain>,
    private UnaryFunctional<Domain> {
public:
    MultiplicativeInverseFunctional(const CloneableObjPtr<IsoFunctional<Domain> >& lhs):
      UnaryFunctional<Domain>(lhs){
    }
    virtual Domain operator()(const Domain& v) const {
       return inverse( lhs()(v) );
    }
    virtual MultiplicativeInverseFunctional<Domain>* clone() const {
      return new MultiplicativeInverseFunctional<Domain>(*this);
    }
};

#endif

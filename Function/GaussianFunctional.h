/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GaussianFunctionalH
#define GaussianFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"
#include "SciEng/utils.h"
  

template<class Domain>
class GaussianFunctional :
    public virtual IsoFunctional<Domain> {
public:
    GaussianFunctional(
        const IsoFunctional<Domain>& mean,
        const IsoFunctional<Domain>& width
    ) :
        the_mean(mean),
        the_width(width) {
    }

    GaussianFunctional(const Domain& mean, const Domain& width);

    virtual Domain operator()(const Domain& v) const {
        return exp(- sqr( (v - (*the_mean)(v)) / (*the_width)(v) ) );
    }
    virtual GaussianFunctional<Domain>* clone() const { 
        return new GaussianFunctional<Domain>(*this); 
    }
private:
    CloneableObjPtr< IsoFunctional<Domain> > the_mean;
    CloneableObjPtr< IsoFunctional<Domain> > the_width;
    };


    #ifndef XLC_QNOTEMPINC
    #include "Function/GaussianFunctional.c"
    #endif

    #endif

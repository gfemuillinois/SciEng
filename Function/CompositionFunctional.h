/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CompositionFunctionalH
#define CompositionFunctionalH

// This should be called CompositionIsoFunctional,
// it takes Domain->Domain->Domain.

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"
                                                
template<class Domain>
class CompositionFunctional :
  public virtual IsoFunctional<Domain> {
public:
  CompositionFunctional(
       const CloneableObjPtr< IsoFunctional<Domain> >& inner,
       const CloneableObjPtr< IsoFunctional<Domain> >& outer
  ) :
    the_inner(inner),
    the_outer(outer) {
  }
  
  virtual Domain operator()(const Domain& v) const { return (*the_outer)( (*the_inner)(v) ); }
  virtual CompositionFunctional<Domain>* clone() const { return new CompositionFunctional<Domain>(*this); }
  
private:
  CloneableObjPtr< IsoFunctional<Domain> > the_inner;
  CloneableObjPtr< IsoFunctional<Domain> > the_outer;
};

#endif

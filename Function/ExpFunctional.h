/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ExpFunctionalH
#define ExpFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class ExpFunctional :
  public virtual IsoFunctional<Domain> {
public:
  virtual Domain operator()(const Domain& v) const { return exp(v); }
  virtual ExpFunctional<Domain>* clone() const { return new ExpFunctional<Domain>(*this); }
};
#endif

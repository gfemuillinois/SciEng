/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SinFunctionalH
#define SinFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class SinFunctional :
  public virtual IsoFunctional<Domain> {
public:
  virtual Domain operator()(const Domain& v) const { return sin(v); }
  virtual SinFunctional<Domain>* clone() const { return new SinFunctional<Domain>(*this); }
};
#endif

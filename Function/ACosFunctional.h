/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ACosFunctionalH
#define ACosFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class ACosFunctional :
  public virtual IsoFunctional<Domain> {
public:
  virtual Domain operator()(const Domain& v) const {
    return acos(v);
  }
  virtual ACosFunctional<Domain>* clone() const { return new ACosFunctional<Domain>(*this); }
};
#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LogFunctionalH
#define LogFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class LogFunctional :
  public virtual IsoFunctional<Domain> {
public:
  virtual Domain operator()(const Domain& v) const {
    return log(v);
  }
  virtual LogFunctional<Domain>* clone() const { return new LogFunctional<Domain>(*this); }
};
#endif

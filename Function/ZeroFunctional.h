/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ZeroFunctionalH
#define ZeroFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"

template<class Domain>
class ZeroFunctional :
    public IsoFunctional<Domain> {
public:
    virtual Domain operator()(const Domain& v) const { return 0.0; }
    virtual ZeroFunctional<Domain>* clone() const { return new ZeroFunctional<Domain>(*this); }
};

#endif

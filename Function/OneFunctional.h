/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef OneFunctionalH
#define OneFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class OneFunctional :
    public IsoFunctional<Domain> {
public:
    virtual Domain operator()(const Domain& v) const { return 1.0; }
    virtual OneFunctional<Domain>* clone() const { return new OneFunctional<Domain>(*this); }
};

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConstantFunctionalH
#define ConstantFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"


template<class Domain>
class ConstantFunctional :  // Always returns its initial value.
    public virtual IsoFunctional<Domain> {      
public:
    ConstantFunctional(Domain r) : the_obj(r){ }

    virtual Domain operator()(const Domain& v) const { return the_obj; }

    virtual ConstantFunctional<Domain>* clone() const { 
        return new ConstantFunctional<Domain>(*this); 
    }
private:
    Domain the_obj;
};


#endif

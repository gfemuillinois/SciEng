/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ParameterFunctionalH
#define ParameterFunctionalH

#include "Function/Functional.h"
#include "SciEng/Ptrs.h"
      

template<class Domain>
class ParameterFunctional :        
    public virtual IsoFunctional<Domain> {
public:

    ParameterFunctional(const Domain& r) : the_range_obj( new Domain(r) ){ }

    ParameterFunctional(const CountedBuiltInPtr<Domain>& r) : the_range_obj(r){ }

    virtual Domain operator()(const Domain& v) const { return *the_range_obj; }
    virtual ParameterFunctional<Domain>* clone() const { return new ParameterFunctional<Domain>(*this); }


    Domain&       value()       { return *the_range_obj; }
    const Domain& value() const { return *the_range_obj; }


private:
    CountedBuiltInPtr<Domain> the_range_obj;
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ModelParameterH
#define ModelParameterH

#include "Function/FunctionalAlgebra.h"
#include "SciEng/Ptrs.h"
#include "SciEng/Subscript.h"

// These objects must work in expressions with FunctionalAlgebra<RallT,RallT>.
//   Their values must accessible via DataModelParameters interface, 
//      for reseting after each iteration.
//   They must be simple to construct.


template<class RallT>
class ModelParameter :  

    private CountedBuiltInPtr<RallT>,           // This base must preceed FunctionalAlgebra.
    public  FunctionalAlgebra<RallT> {          // Usable in FunctionalAlgebra expressions.

public:

    ModelParameter(double initial_guess = 0.0);   // Constrained.
    ModelParameter(double initial_guess, Subscript i_th, Subscript nparms); // Varying.

    ModelParameter<RallT>& operator=(double rhs);
    ModelParameter<RallT>& operator=(const ModelParameter<RallT>& rhs);


    const RallT& value() const { return *(const CountedBuiltInPtr<RallT>&)(*this); }
          RallT& value()       { return *(const CountedBuiltInPtr<RallT>&)(*this); }

};



#ifdef XLC_QNOTEMPINC
#include "DataModeling/ModelParameter.c"
#endif

#endif

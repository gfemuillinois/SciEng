/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LinearizedEquationsBaseH
#define LinearizedEquationsBaseH


#include "DataModeling/IteratedEquations.h"
#include "SciEng/Ptrs.h"
#include "DataModeling/DataModel.h"
#include "DataModeling/PhysicalData.h"


template<class Range>
class LinearizedEquationsBase :                        // Implementation Base 
    public virtual IteratedEquations< Range > {      
public:
    virtual const Array1d<Range>& initialValues() const {return x_0;}
    virtual Boolean converged() const { return limit > the_chi2; }
protected:
    LinearizedEquationsBase( 
        const PhysicalData<Range>& data_to_fit,
        const DataModel<Range>& model
    );
    const PhysicalData<Range>& the_data_ptr;
    const DataModel<Range>& the_model;
    FormedArray1d<Range> x_0;
    Range limit;
    Range the_chi2;
};


#ifdef XLC_QNOTEMPINC
#include "DataModeling/LinearizedEquationsBase.c"
#endif

#endif


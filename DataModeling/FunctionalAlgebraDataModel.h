/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FunctionalAlgebraDataModelH
#define FunctionalAlgebraDataModelH

#include "SciEng/Ptrs.h"
#include "Function/FunctionalAlgebra.h"

#include "DataModeling/DataModel.h"
#include "DataModeling/DataModelParameters.h"
#include "Function/FunctionalAlgebra.h"
#include "AutoDeriv/Rall1d.h"
#include "Vector/ElasticArithmetic.h"


template<class T>
class FunctionalAlgebraDataModel :  
    public virtual DataModel<T> {
public:
    typedef Rall1d<double, ElasticArithmetic1d<double> > RallT;
    FunctionalAlgebraDataModel(const FunctionalAlgebra<RallT>&, const DataModelParameters<RallT,T>&);

    virtual TaylorCoefficient1d<T> operator()(const T& coordinate) const;
    virtual FunctionalAlgebraDataModel<T>* clone() const { return new FunctionalAlgebraDataModel<T>(*this); }

protected:
    FunctionalAlgebraDataModel(Subscript number_of_variables);
    FunctionalAlgebra< RallT > f;
    DataModelParameters<RallT, T> parms;  //  parameter storage implementation.
    virtual const Array1d<T>& parameters() const { return parms; }
    virtual Array1d<T>& parameters() { return parms; }
};


#ifdef XLC_QNOTEMPINC
#include "DataModeling/FunctionalAlgebraDataModel.c"
#endif

#endif

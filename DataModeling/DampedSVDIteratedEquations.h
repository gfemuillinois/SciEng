/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DampedSVDIteratedEquationsH
#define DampedSVDIteratedEquationsH


#include "DataModeling/IteratedEquations.h"
#include "DataModeling/DataModel.h"
#include "LapackWrap/Lapack.h"
#include "DataModeling/LeastSquares.h"
#include "LapackWrap/DampedRectSVDRep.h"
#include "LapackWrap/ConcreteBlas2d.h"


template<class T>
class DampedSVDIteratedEquations :
    public virtual IteratedEquations<T> {
public:
    DampedSVDIteratedEquations(PhysicalData<T>& data_to_fit, DataModel<T>& model_to_use);

    virtual const Array1d<T>& initialValues()     const { return z_0; }
    virtual Boolean           converged()         const { return limit > lse.chi2(); }
    virtual T                 update(Array1d<T>&);

private:
    // Abbreviations for matrix storage wrapper classes.
    typedef LapackUnfactored< DampedRectSVDRep< T > > Unfactored;
    typedef LapackFactored< DampedRectSVDRep< T > > Factored;


    PhysicalData<T>&         data;       // Data
    DataModel<T>&            model;      // Model
    FormedArray1d<T>         z_0;        // Initial parameters
    T                        limit;      // Convergence in chi^2
    T                        lambda2;    // Damping factor
    LeastSquares<Unfactored> lse;        // Current linearization.
    ConcreteBlas1d<T>        z;          // Current parameter set.

};



#ifdef XLC_QNOTEMPINC
#include "DataModeling/DampedSVDIteratedEquations.c"
#endif

#endif


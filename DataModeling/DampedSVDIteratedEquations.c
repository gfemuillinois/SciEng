/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/arrayCopy.h"


template<class T>
DampedSVDIteratedEquations<T>::
DampedSVDIteratedEquations(PhysicalData<T>& data_to_fit, DataModel<T>& model_to_use) :
    data(data_to_fit),
    model(model_to_use),
    z_0(model.parameters()),
    lse( data, model, model.parameters().numElts() ),
    lambda2(0.001), // Value recommended by Numerical Recipes and Marquardt.
    z(model.parameters().numElts()) {

    arrayCopy(z, model.parameters());
    ConcreteBlas1d<T> x(z);
    LeastSquares<Unfactored> trial(lse);    // Save data (from overwrite in factor).

    Factored usvt = trial.factor();         // A -> U*S*V^T
    usvt.rep().dampingFactor() = lambda2;
    usvt.solve(x, trial.rhs());             // x from Ax=b via damped SVD.

    arrayCopy(model.parameters(),x + z);    // Initial step.

}




template<class T>
T DampedSVDIteratedEquations<T>::update(Array1d<T>& parms){ 

    // Update model.
    model.parameters() = parms;

    // Linearize non-linear equations and evaluate new chi-squared.
    LeastSquares<Unfactored> trial( data, model, parms.numElts() );


    if ( trial.chi2() < lse.chi2() ) {         // If we are going down hill,
       lse  = trial;                           // accept this equation set,
       arrayCopy(z, parms);                    // record its parameters,
       lambda2 /= 10.0;                        // reduce damping.
    }
    else {                                     // If we are going up hill,
       trial = lse;                            // overwrite this equation set,
                                               // ignore its parameters,
       lambda2 *= 10.0;                        // increase damping.
    }


    ConcreteBlas1d<T> x(parms.numElts());      // Update-vector storage.

    Factored usvt = trial.factor();            // A -> U*S*V^T
    usvt.rep().dampingFactor() = lambda2;
    usvt.solve(x, trial.rhs());                // x for Ax=b by damped SVD

    arrayCopy(parms, x + z);                   // x = a - z => a = x + z.

    return x.norm();

}



 


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class Range>
LevenbergMarquardtEquations<Range>::LevenbergMarquardtEquations(
    const PhysicalData<Range>& data_to_fit,
    const DataModel<Range>& model
  ):
  LinearizedEquationsBase<Range>(data_to_fit, model),
  hessian(the_model.parameters().numElts()),
  lamda(0.001) {  // Value recommended by Numerical Recipes in C and Marquardt.
}
 
#include "LapackWrap/ConcreteBlas1d.h"


template<class Range>
Range LevenbergMarquardtEquations<Range>::update(Array1d<Range>& parms){ 

                      // Update model.
    the_model.parameters() = parms;

                      // Linearize non-linear equations and evaluate new chi-squared.
    LevenbergMarquardtHessian<Range> trial( *the_data_ptr, *the_model );



    if ( trial.chi2() < hessian.chi2() ) {        // If we are going down hill,
        hessian = trial;                          // accept solution,
        hessian.doMarquardt( 1.0 + lamda );       // fudge it like Marquardt suggests,
        lamda /= 10.0;                            // and reduce the fudge factor for next time.
    }
    else {                                        // If we are going up hill,
        lamda *= 10.0;                            // up the fudge factor,
        hessian.doMarquardt( 1.0 + lamda );       // and refudge the current hessian.
    }

    trial = hessian;                              // factor temp, save unfactored one.
    ConcreteBlas1d<Range> x_old(parms);
    ConcreteBlas1d<Range> delta_x(parms);

    trial.factor().solve(delta_x);

    parms = (x_old - delta_x);                    // x_new = x_old + (- d_x).

    return delta_x.norm();

}

 


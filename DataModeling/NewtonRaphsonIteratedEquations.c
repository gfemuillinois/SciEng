/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "LapackWrap/Lapack.h"
#include "LapackWrap/BlasRectLURep.h"
#include "Array/arrayCopy.h"


template<class RallT>
NewtonRaphsonIteratedEquations<RallT>::
NewtonRaphsonIteratedEquations(int n_eqns, T function_convergence) : 
    FormedArray1d< NewtonRaphsonFunction<RallT> > (n_eqns), 
    function_value(function_convergence),                   // converged()==false 1st time for sure.
    function_value_convergence(function_convergence) {
}



template<class RallT>
NewtonRaphsonIteratedEquations<RallT>::T NewtonRaphsonIteratedEquations<RallT>::
update(Array1d< NewtonRaphsonIteratedEquations<RallT>::T>& a) { 

    Subscript n = a.shape(0);
    ConcreteBlas1d<T> x(n);
    arrayCopy(x, a);

    FormedArray1d< RallT > a_trial(n);
    for (int i = 0; i < n; i++) {   
                                                            a_trial(i) = RallT(a(i), i, n);  // Convert a_i's to Rall numbers
    }

    LapackUnfactored< BlasRectLURep<T> >  jacobian(n, n);
    ConcreteBlas1d<T> delta_a(n);

    Array1d< NewtonRaphsonFunction<RallT> >& f = *this;

    for (i = 0; i < n; i++) { // Evaluate equations, unpack derivatives
                                                            TaylorCoefficient1d<T> f_a_trial = f(i)(a_trial);

                                                            jacobian.row(i) = f_a_trial;
                                                            delta_a(i)      = f_a_trial.value();

    }


    jacobian.factor().solve(delta_a);          // Solve for correction.
    x -= delta_a;                              // Apply correction.
    arrayCopy(a, x);                           // Store results.
    function_value = x.norm();                 // Save for convergence test.


    return delta_a.norm();
}


template<class RallT>
Boolean NewtonRaphsonIteratedEquations<RallT>::converged() const {
  // Compare norm to limit, stop when we know answer.
  return function_value < function_value_convergence;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
NewtonRaphson<T>::NewtonRaphson(unsigned int iters, T fc, T cc):
  iters_(iters),
  function_convergence_(fc),
  corrections_convergence_(cc){
}
  

#include "LapackWrap/BlasRectLURep.h"
#include "AutoDeriv/LapackArithmetic.h"
                           
template<class T>
Array1d<T>& NewtonRaphson<T>::solve(DifferentiableEquations<T>& eqns, Array1d<T>& initial_values){
  // Solve eqns == 0 beginning at initial_values by method of NewtonRaphson, 
  // as descibed in "Numerical Recipes", Press, Flannery, Teukolsky, and Vetterling.
  
  int old_precision = cout.precision(NumericalLimits<T>::digits);  // Get sig-figs on iteration output.
  
  int nvars = initial_values.numElts();
  Blas2d<T> current(nvars,1);
  
  current[0] = initial_values;
  
  int i = 0;
  while (i++ < iters_) {
  
    eqns.evaluateAt(current[0]);
    if ( eqns.converged_to(function_convergence_) ) break;
    Blas2d<T> d(nvars,1);
    d[0] = eqns.value();
    
    LapackArithmetic< BlasRectLURep<T>, T > j = eqns.jacobian();
    j.factor().solve(d);   // Solve for correction.

    if (d[0].norm() < corrections_convergence_) break;
    current -= d;          // Apply Correction.
    
    cout << "Newton-Raphson Iteration " << i << " of " << iters_ << " gives " << current << endl;
  }
  initial_values = current[0];    // store results.
  cout.precision(old_precision);  // Reset sig-figs.
  return initial_values;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NewtonRaphsonH
#define NewtonRaphsonH

#include "SciEng/NumericalLimits.h"
#include "AutoDeriv/DifferentiableEquations.h"

#include "Array/Array1d.h"


template<class T>
class NewtonRaphson {
public:
  NewtonRaphson(
     unsigned int iters,
     T function_convergence = NumericalLimits<T>::epsilon,    // Tested for close to root.
     T corrections_convergence = NumericalLimits<T>::epsilon  // Tested for no movement towards root.
  );

  Array1d<T>& solve(DifferentiableEquations<T>& eqns, Array1d<T>& initial_values);
  
protected:
  T function_convergence_;
  T corrections_convergence_;
  int iters_;
};

#ifdef XLC_QNOTEMPINC
#include "AutoDeriv/NewtonRaphson.c"
#endif
      
#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>

#include "DataModeling/NewtonRaphsonIteratedEquations.h"
#include "DataModeling/LinearizationIterator.h"
#include "AutoDeriv/RigidRall1d.h"
#include "SciEng/utils.h"


template<class T>
T gorlen5p3_f(const Array1d<T>& a){  
    return 16.0 * pow(a(0), 4) + 16.0 * pow(a(1), 4) + pow(a(2), 4) - T(16.0);
}

template<class T>
T gorlen5p3_g(const Array1d<T>& a){  
    return a(0)*a(0) + a(1)*a(1) + a(2)*a(2) - T(3.0);
}

template<class T>
T gorlen5p3_h(const Array1d<T>& a){ 
    return pow(a(0), 3) - a(1);
}


int main() { 


cout << "Finding Zeros of Nonlinear Equations Test " << endl
     << "Equations 5.3 in Gorlen, Orlow and Plexico, " << endl
     << "Data Abstraction and Object Oriented Programming in C++" << endl;


  typedef RigidRall1d<double, 3> RallT;

  NewtonRaphsonIteratedEquations<RallT> eqns(3); // 3 equations in 3 unknowns

  eqns(0) = gorlen5p3_f;   // Store functions
  eqns(1) = gorlen5p3_g;
  eqns(2) = gorlen5p3_h;


  FormedArray1d<double> rhs(3); // Variables
  rhs = 1.0;                    // Initial guess = [1, 1, 1]


  // Solve equations, using at most 10 iterations
  LinearizationIterator<double> solver(eqns, rhs, 10);
  solver.solve();
  
  cout << "Zeros are: " << setprecision(NumericalLimits<double>::digits) << solver.current() << endl;

//  cout << "Rall reports: 0.8.77965760274, 0.676756970518, 1.33085541162 " << endl;
  return EXIT_SUCCESS;
}



//
// Timing and testing LapackWrap

#include <iostream>
#include <math.h>
#include <cstdlib>  // for rand()
#include <typeinfo>

#include "timer.h"
#include "LapackWrap/LapackWrap.h"
#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL  0
#define TEST1     1

#if TEST1 || TEST_ALL
  cout << "\nTest/timing factAndSolve " << endl;

  {
    const int mat_dim = 10;
    const int prob_dim = 8;

    cout << "\nmat_dim = " << mat_dim << " prob_dim = " << prob_dim << endl;

    // creates a solution. 
    ConcreteRigidArray1d< double, mat_dim>  U;
    U = -1.0;
    for(Subscript i=0; i<prob_dim; ++i)
      U(i) = i;  

    cout << "\nCooked solution:" << U << endl;

    // Fill lhs with randon numbers
    ConcreteRigidArray2d< double, mat_dim,mat_dim>  A;

    for(Subscript i=0; i<prob_dim; ++i){
      for(Subscript j=0; j<prob_dim; ++j){
	A(i,j) = static_cast<double>( rand() )/RAND_MAX;
      }
    }    

    // Manufacture a rhs such that the solution is equal to U:
    // rhs = A * U
    ConcreteRigidArray1d< double, mat_dim>  rhs;
    rhs = -2.;
    for(Subscript i=0; i<prob_dim; ++i) {
      rhs(i) = 0.;
      for(Subscript j=0; j<prob_dim; ++j) {
	rhs(i) += A(i,j) * U(j);
      }
    }

    cout << "\nCooked rhs = A * U:" << rhs << endl;

    the_timer.set(0);
    the_timer.start(0);

    if ( LapackWrap::factAndSolve( A, prob_dim, rhs) ) {
      cout << "\nSolution:" << rhs << endl;
    }
    else {
      cout << "\nfactAndSolve Failed!!" << endl;
      the_timer.stop(0);
      return EXIT_FAILURE;
    }

    the_timer.stop(0);
    cout << "\n Time spent  (s) = " << the_timer.read(0) << endl;

  }
#endif

  return EXIT_SUCCESS;
}
// ***************************************************
// ***************************************************

//
// Timing matrix multiplication using operator() from varios
// 3D arrays

#include <iostream>
#include <cstdlib>

#include "timer.h"
#include "Array/ConcreteRigidArray3d.h"

#include "Array/ConcreteFormedArray3d.h"

using std::cout;
using std::endl;

Timer  the_timer(10);	// 10 clocks

int main() {

  const int mat_dim = 25;
  const int nmult = 2000; 

  the_timer.set(0);
  the_timer.start(0);

  double bia_a[mat_dim][mat_dim][mat_dim], bia_b[mat_dim][mat_dim][mat_dim], 
    bia_c[mat_dim][mat_dim][mat_dim];
   
  for(int imult=0; imult<nmult; ++imult) {
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	for(int k=0; k<mat_dim; ++k) {
	  bia_a[i][j][k] = 0.0;
	  bia_b[i][j][k] = 1.0;
	  bia_c[i][j][k] = 2.0;
	}

    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	for(int k=0; k<mat_dim; ++k)
	  for(int l=0; l<mat_dim; ++l)
	    bia_a[i][j][k] += bia_b[i][j][l] * bia_c[i][l][k];
  }
  the_timer.stop(0);
  cout << "\n Time spent with built in arrays (s) = "
       << the_timer.read(0) << endl;

  the_timer.set(1);
  the_timer.start(1);

  ConcreteRigidArray3d<double, mat_dim, mat_dim, mat_dim> cra_a, cra_b, cra_c;
   
  for(int imult=0; imult<nmult; ++imult) {
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	for(int k=0; k<mat_dim; ++k) {
	  cra_a(i,j,k) = 0.0;
	  cra_b(i,j,k) = 1.0;
	  cra_c(i,j,k) = 2.0;
	}

    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	for(int k=0; k<mat_dim; ++k)
	  for(int l=0; l<mat_dim; ++l)
	    cra_a(i,j,k) += cra_b(i,j,l) * cra_c(i,l,k);
  }
  the_timer.stop(1);
  cout << "\n Time spent with ConcreteRigid arrays 3d (s) = "
       << the_timer.read(1) << endl;
    
  the_timer.set(2);
  the_timer.start(2);

  ConcreteFormedArray3d<double>  cfa_a(mat_dim, mat_dim, mat_dim), 
    cfa_b(mat_dim, mat_dim, mat_dim), cfa_c(mat_dim, mat_dim, mat_dim);
   
  the_timer.set(3);
  the_timer.start(3);

  for(int imult=0; imult<nmult; ++imult) {
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	for(int k=0; k<mat_dim; ++k) {
	  cfa_a(i,j,k) = 0.0;
	  cfa_b(i,j,k) = 1.0;
	  cfa_c(i,j,k) = 2.0;
	}
      
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	for(int k=0; k<mat_dim; ++k)
	  for(int l=0; l<mat_dim; ++l)
	    cfa_a(i,j,k) += cfa_b(i,j,l) * cfa_c(i,l,k);
  }
  the_timer.stop(3);
  cout << "\n Time spent with ConcreteFormed arrays 3d (s) = "
       << the_timer.read(3) << endl;


  the_timer.stop(2);
  cout << "\n Time spent with ConcreteFormed arrays 3d (s) "
       << " \n(includes memory allocation) = "
       << the_timer.read(2) << endl;
   
  // Check computations:

  bool fail = false;
  for(int i=0; i<mat_dim; ++i)
    for(int j=0; j<mat_dim; ++j)
      for(int k=0; k<mat_dim; ++k) {
	if ( fabs( cfa_a(i,j,k) -  bia_a[i][j][k] ) > 1.0e-14 ) {
	  std::cerr << "\nWARNING! cfa_a(i,j,k) != bia_a[i][j][k]" << endl;
	  fail = true;
	}
	if ( fabs( cra_a(i,j,k) -  bia_a[i][j][k] ) > 1.0e-14 ) {
	  std::cerr << "\nWARNING! cra_a(i,j,k) != bia_a[i][j][k]" << endl;
	  fail = true;
	}
      }
  if (!fail)
    cout << "\n ** All computations checked OK **" << endl;

  return EXIT_SUCCESS;
}
// ***************************************************
// ***************************************************


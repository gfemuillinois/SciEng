//
// Timing matrix multiplication using operator() from varios
// arrays

#include <iostream>
#include <cstdlib>

#include "timer.h"
#include "Array/ConcreteRigidArray2d.h"

#include "Array/ConcreteFormedArray2d.h"

Timer  the_timer(10);	// 10 clocks

int main() {

const int mat_dim = 50;
const int nmult = 2000; 

 {
   the_timer.set(0);
   the_timer.start(0);

   double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim], 
     bia_c[mat_dim][mat_dim];
   
   for(int imult=0; imult<nmult; ++imult) {
     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j) {
	 bia_a[i][j] = 0.0;
	 bia_b[i][j] = 1.0;
	 bia_c[i][j] = 2.0;
       }

     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j)
	 for(int k=0; k<mat_dim; ++k)
	   bia_a[i][j] += bia_b[i][k] * bia_c[k][j];
   }
   the_timer.stop(0);
   cout << "\n Time spent with built in arrays (s) = "
	<< the_timer.read(0) << endl;
 }
 {
   the_timer.set(1);
   the_timer.start(1);

   ConcreteRigidArray2d<double, mat_dim, mat_dim> cra_a, cra_b, cra_c;
   
   for(int imult=0; imult<nmult; ++imult) {
     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j) {
	 cra_a(i,j) = 0.0;
	 cra_b(i,j) = 1.0;
	 cra_c(i,j) = 2.0;
       }

     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j)
	 for(int k=0; k<mat_dim; ++k)
	   cra_a(i,j) += cra_b(i,k) * cra_c(k,j);
   }
   the_timer.stop(1);
   cout << "\n Time spent with ConcreteRigid arrays (s) = "
	<< the_timer.read(1) << endl;

 }
 {
   the_timer.set(2);
   the_timer.start(2);

   ConcreteFormedArray2d<double>  cfa_a(mat_dim, mat_dim), 
     cfa_b(mat_dim, mat_dim), cfa_c(mat_dim, mat_dim);
   
   the_timer.set(3);
   the_timer.start(3);

   for(int imult=0; imult<nmult; ++imult) {
     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j) {
	 cfa_a(i,j) = 0.0;
	 cfa_b(i,j) = 1.0;
	 cfa_c(i,j) = 2.0;
       }

     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j)
	 for(int k=0; k<mat_dim; ++k)
	   cfa_a(i,j) += cfa_b(i,k) * cfa_c(k,j);
   }
   the_timer.stop(3);
   cout << "\n Time spent with ConcreteFormed arrays (s) = "
	<< the_timer.read(3) << endl;


   the_timer.stop(2);
   cout << "\n Time spent with ConcreteFormed arrays (s) "
	<< " \n(includes memory allocation) = "
	<< the_timer.read(2) << endl;
   
   // bypassing operator()

   the_timer.set(4);
   the_timer.start(4);

   for(int imult=0; imult<nmult; ++imult) {
     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j) {
	 cfa_a.firstDatum()[ i*mat_dim + j] = 0.0;
	 cfa_b.firstDatum()[ i*mat_dim + j] = 1.0;
	 cfa_c.firstDatum()[ i*mat_dim + j] = 2.0;
       }

     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j)
	 for(int k=0; k<mat_dim; ++k)
	   cfa_a.firstDatum()[ i*mat_dim + j] +=
	     cfa_b.firstDatum()[ i*mat_dim + k] *
	     cfa_c.firstDatum()[ k*mat_dim + j];
   }
   the_timer.stop(4);
   cout << "\n Time spent with ConcreteFormed arrays (s) "
	<< "\n(bypassing operator()) = "
	<< the_timer.read(4) << endl;

   // bypassing firstDatum()

   double *p_cfa_a = cfa_a.firstDatum();
   double *p_cfa_b = cfa_b.firstDatum();
   double *p_cfa_c = cfa_c.firstDatum();


   the_timer.set(6);
   the_timer.start(6);

   for(int imult=0; imult<nmult; ++imult) {
     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j) {
	 p_cfa_a[ i*mat_dim + j] = 0.0;
	 p_cfa_b[ i*mat_dim + j] = 1.0;
	 p_cfa_c[ i*mat_dim + j] = 2.0;
       }

     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j)
	 for(int k=0; k<mat_dim; ++k)
	   p_cfa_a[ i*mat_dim + j] +=
	     p_cfa_b[ i*mat_dim + k] *
	     p_cfa_c[ k*mat_dim + j];
   }
   the_timer.stop(6);
   cout << "\n Time spent with ConcreteFormed arrays (s) "
	<< "\n(bypassing operator()and firstDatum()) = "
	<< the_timer.read(6) << endl;
 }

 {
   // Doing everything....

   double *da_a = new double[mat_dim*mat_dim];
   double *da_b = new double[mat_dim*mat_dim];
   double *da_c = new double[mat_dim*mat_dim];

   the_timer.set(5);
   the_timer.start(5);

   for(int imult=0; imult<nmult; ++imult) {
     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j) {
	 da_a[ i*mat_dim + j] = 0.0;
	 da_b[ i*mat_dim + j] = 1.0;
	 da_c[ i*mat_dim + j] = 2.0;
       }

     for(int i=0; i<mat_dim; ++i)
       for(int j=0; j<mat_dim; ++j)
	 for(int k=0; k<mat_dim; ++k)
	   da_a[ i*mat_dim + j] +=
	     da_b[ i*mat_dim + k] *
	     da_c[ k*mat_dim + j];
   }
   the_timer.stop(5);
   cout << "\n Time spent with arrays from heap (s) = "
	<< the_timer.read(5) << endl;

   delete [] da_a;
   delete [] da_b;
   delete [] da_c;



 }
 /* Best timings so far: 
    const int mat_dim = 500; 
    const int nmult = 1;

    Time spent with built in arrays (s) = 6.22

    Time spent with ConcreteRigid arrays (s) = 5.71

    Time spent with ConcreteFormed arrays (s) = 10.9

    Time spent with ConcreteFormed arrays (s)  
    (includes memory allocation) = 10.9

    Time spent with ConcreteFormed arrays (s) 
    (bypassing operator()) = 9.73

    Time spent with ConcreteFormed arrays (s) 
    (bypassing operator()and firstDatum()) = 6.43

    Time spent with arrays from heap (s) = 6.42

    ---
    original timing (without code tuning):
    const int mat_dim = 50;
    const int nmult = 2000; 

     Time spent with built in arrays (s) = 5.8

     Time spent with ConcreteRigid arrays (s) = 5.47
     
     Time spent with ConcreteFormed arrays (s) = 22.56

     Time spent with ConcreteFormed arrays (s)  
     (includes memory allocation) = 22.56

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()) = 11.48

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()and firstDatum()) = 6.74

     Time spent with arrays from heap (s) = 6.73

     ---
     after some tunning (specialization of subscriptors
     and using offset(Subscript, Subscript)

     Time spent with built in arrays (s) = 5.78

     Time spent with ConcreteRigid arrays (s) = 5.4

     Time spent with ConcreteFormed arrays (s) = 12.65

     Time spent with ConcreteFormed arrays (s)  
     (includes memory allocation) = 12.65

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()) = 10.49

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()and firstDatum()) = 6.08

     Time spent with arrays from heap (s) = 6.15
 */

 return EXIT_SUCCESS;
}
// ***************************************************
// ***************************************************


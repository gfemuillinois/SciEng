//
// Timing dot product using operator() from 
// Concrete and Rigid Array 2d

#include <iostream>
#include <cstdlib>

#include "timer.h"
#include "Array/ConcreteRigidArray2d.h"

#include "Array/ConcreteFormedArray2d.h"
#include "Array/ConcreteFortranArray2d.h"

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL 1

#define TEST1 1 // Test/timing for operator() 

#define TEST2 1 // Test/timing for operator=(const T& rhs)

#define TEST3 1 // Test/timing for operator=(const Array& rhs)


#if TEST1
  {
  cout << "\nTest/timing for operator()" << endl;

  const int mat_dim = 10;
  const int n_prods = 20000;  
  {
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim];
    double result;

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  bia_a[i][j] = bia_b[i][j] = double(i+j)/mat_dim;
	}
      }
      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  result += bia_a[i][j] * bia_b[i][j];
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    cout << "Result = " << result << endl;
  }

  {
    the_timer.set(1);
    the_timer.start(1);

    ConcreteRigidArray2d<double, mat_dim, mat_dim> cra_a, cra_b;
    double result;

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<mat_dim; ++i) {
	for(Subscript j=0; j<mat_dim; ++j) {
	  cra_a(i,j) = cra_b(i,j) = double(i+j)/mat_dim;
	}
      }
      for(Subscript i=0; i<mat_dim; ++i)
	for(Subscript j=0; j<mat_dim; ++j)
	  result += cra_a(i,j) * cra_b(i,j);
    }
    the_timer.stop(1);
    cout << "\n Time spent with ConcreteRigid arrays (s) = "
	 << the_timer.read(1) << endl;
    cout << "Result = " << result << endl;
  }

  {
    the_timer.set(2);
    the_timer.start(2);

    ConcreteFormedArray2d<double>  cfa_a(mat_dim,mat_dim),
                                   cfa_b(mat_dim,mat_dim);
    //ConcreteFortranArray2d<double>  cfa_a(mat_dim,mat_dim),
    //                                cfa_b(mat_dim,mat_dim);
   
    the_timer.set(3);
    the_timer.start(3);
    double result;

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<mat_dim; ++i) {
	for(Subscript j=0; j<mat_dim; ++j) {
	  cfa_a(i,j) = cfa_b(i,j) = double(i+j)/mat_dim;
	}
      }
      for(Subscript i=0; i<mat_dim; ++i)
	for(Subscript j=0; j<mat_dim; ++j)
	  result += cfa_a(i,j) * cfa_b(i,j);
    }

    the_timer.stop(3);
    cout << "\n Time spent with ConcreteFormed arrays (s) = "
	 << the_timer.read(3) << endl;
    cout << "Result = " << result << endl;

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteFormed arrays (s) "
	 << " \n(includes memory allocation) = "
	 << the_timer.read(2) << endl;
  }
  }

  /*
    Test/timing for operator()
    const int mat_dim = 50;
    const int n_prods = 20000;  

    Time spent with built in arrays (s) = 6.17
    Result = 2817.5

    Time spent with ConcreteRigid arrays (s) = 7.15
    Result = 2817.5

    Time spent with ConcreteFormed arrays (s) = 6.07
    Result = 2817.5

    Time spent with ConcreteFormed arrays (s)  
    (includes memory allocation) = 6.07
  */
#endif 

#if TEST2
  {
  cout << "\nTest/timing for operator=(const T& rhs)" << endl;

  const int mat_dim = 50;
  const unsigned int n_equal = 100000;
    
  {
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim];
    double value = 0.0;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  bia_a[i][j] = value;
	}
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
  }
  {
    // Built in array in the heap

    double *da_a = new double[mat_dim*mat_dim];
    double *da_b = new double[mat_dim*mat_dim];
    double value = 0.0;

    the_timer.set(1);
    the_timer.start(1);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  da_a[i*mat_dim + j] = value;
	}
      }
    }

    the_timer.stop(1);
    cout << "\n Time spent with arrays from heap (s) = "
	 << the_timer.read(1) << endl;

    delete [] da_a;
    delete [] da_b;
  }  
  {
    the_timer.set(2);
    the_timer.start(2);

    ConcreteRigidArray2d<double, mat_dim, mat_dim> cra_a, cra_b;
    double value = 0.0;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteRigid arrays (s) = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_a(i,j) != value || cra_a[i][j] != value ) { 
	  cout << "error: expected " << value << " found " << cra_a(i,j) << endl;
	  return EXIT_FAILURE;
	}
      }
    }
  }
  {
    ConcreteFormedArray2d<double>  cfa_a(mat_dim,mat_dim), cfa_b(mat_dim,mat_dim);
    //ConcreteFortranArray2d<double>  cfa_a(mat_dim,mat_dim), cfa_b(mat_dim,mat_dim);
   
    the_timer.set(3);
    the_timer.start(3);
    double value = 0.0;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cfa_a = value;
    }

    the_timer.stop(3);
    cout << "\n Time spent with ConcreteFormed arrays (s) = "
	 << the_timer.read(3) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cfa_a(i,j) != value || cfa_a[i][j] != value ) {
	cout << "error: expected " << value << " found " << cfa_a(i,j) << endl;
	  return EXIT_FAILURE;
	}
      }
    }

  }
  }
  /* 
     const int mat_dim = 50;
     const unsigned int n_equal = 100000;
 
     Test/timing for operator=(const T& rhs)

     Time spent with built in arrays (s) = 5.22
     
     Time spent with arrays from heap (s) = 5.18

     Time spent with ConcreteRigid arrays (s) = 4.96
     
     Time spent with ConcreteFortran arrays (s) = 8.78
     Time spent with ConcreteFormed arrays (s) = 7.44
  */
#endif

#if TEST3
  {
  cout << "\nTest/timing for operator=(const Array& rhs)" << endl;

  const int mat_dim = 50;
  const unsigned int n_equal = 100000;
  {
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim];
    double value = 0.0;

    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	bia_b[i][j] = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] = bia_b[i][j];
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
  }
  {
    // Built in array in the heap

    double *da_a = new double[mat_dim*mat_dim];
    double *da_b = new double[mat_dim*mat_dim];
    double value = 0.0;

    the_timer.set(1);
    the_timer.start(1);

    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	da_b[i*mat_dim + j] = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  da_a[i*mat_dim + j] = da_b[i*mat_dim + j];
	}
      }
    }

    the_timer.stop(1);
    cout << "\n Time spent with arrays from heap (s) = "
	 << the_timer.read(1) << endl;

    delete [] da_a;
    delete [] da_b;
  }  

  {
    the_timer.set(2);
    the_timer.start(2);

    ConcreteRigidArray2d<double, mat_dim, mat_dim> cra_a, cra_b;
    double value = 0.0;

    cra_b = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = cra_b;
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteRigid arrays (s) = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_a(i,j) != value || cra_a[i][j] != value ) {
	  cout << "error: expected " << value << " found " << cra_a(i,j) << endl;
	  return EXIT_FAILURE;
	}
      }
    }
  }
  {
    ConcreteFormedArray2d<double>  cfa_a(mat_dim, mat_dim), cfa_b(mat_dim, mat_dim);
    //ConcreteFortranArray2d<double>  cfa_a(mat_dim, mat_dim), cfa_b(mat_dim, mat_dim);
   
    the_timer.set(3);
    the_timer.start(3);
    double value = 0.0;

    cfa_b = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cfa_a = cfa_b;
    }

    the_timer.stop(3);
    cout << "\n Time spent with ConcreteFormed arrays (s) = "
	 << the_timer.read(3) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cfa_a(i,j) != value || cfa_b[i][j] != value ) {
	  cout << "error: expected " << value << " found " << cfa_a(i,j) << endl;
	  return EXIT_FAILURE;
	}
      }
    }
  }
  }

  /*

    const int mat_dim = 50;
    const unsigned int n_equal = 100000;

    Test/timing for operator=(const Array& rhs)

    Time spent with built in arrays (s) = 8.07

    Time spent with arrays from heap (s) = 6.89

    Time spent with ConcreteRigid arrays (s) = 6.74

    Time spent with ConcreteFortran arrays (s) = 11.02
    Time spent with ConcreteFormed arrays (s) = 11.33
  */

#endif 

  return EXIT_SUCCESS;

}
// ***************************************************
// ***************************************************


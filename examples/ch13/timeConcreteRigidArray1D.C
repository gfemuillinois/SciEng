//
// Timing dot product using operator() from 
// Concrete and Rigid Array 1d

#include <iostream>
#include <cstdlib>

#include "timer.h"
#include "Array/ConcreteRigidArray1d.h"

#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFortranArray1d.h"

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL 1

#define TEST1 1 // Test/timing for operator()

#define TEST2 1 // Test/timing for operator=(const T& rhs)

#define TEST3 1 // Test/timing for operator=(const Array& rhs)

#if TEST1 || TEST_ALL
  {
  cout << "\nTest/timing for operator()" << endl;

  const int vec_dim = 250;
  const int n_prods = 200000;  
  {
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double result;

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = bia_b[i] = double(i)/vec_dim;
      }
      for(int i=0; i<vec_dim; ++i)
	result += bia_a[i] * bia_b[i];
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    cout << "Result = " << result << endl;
  }

  {
    the_timer.set(1);
    the_timer.start(1);

    ConcreteRigidArray1d<double, vec_dim> cra_a, cra_b;
    double result;

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<vec_dim; ++i) {
	cra_a(i) = cra_b(i) = double(i)/vec_dim;
      }
      for(Subscript i=0; i<vec_dim; ++i)
	result += cra_a(i) * cra_b(i);
    }
    the_timer.stop(1);
    cout << "\n Time spent with ConcreteRigid arrays (s) = "
	 << the_timer.read(1) << endl;
    cout << "Result = " << result << endl;
  }

  {
    the_timer.set(2);
    the_timer.start(2);

    ConcreteFormedArray1d<double>  cfa_a(vec_dim), cfa_b(vec_dim);
    //ConcreteFortranArray1d<double>  cfa_a(vec_dim), cfa_b(vec_dim);
   
    the_timer.set(3);
    the_timer.start(3);
    double result;

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<vec_dim; ++i) {
	cfa_a(i) = cfa_b(i) = double(i)/vec_dim;
      }
      for(Subscript i=0; i<vec_dim; ++i)
	result += cfa_a(i) * cfa_b(i);
    }

    the_timer.stop(3);
    cout << "\n Time spent with ConcreteFormed arrays (s) = "
	 << the_timer.read(3) << endl;
    cout << "Result = " << result << endl;

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteFormed arrays (s) "
	 << " \n(includes memory allocation) = "
	 << the_timer.read(2) << endl;

    // bypassing operator()

    the_timer.set(4);
    the_timer.start(4);

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<vec_dim; ++i) {
	cfa_a.firstDatum()[i] = cfa_b.firstDatum()[i] = double(i)/vec_dim;
      }
      for(Subscript i=0; i<vec_dim; ++i)
	result += cfa_a.firstDatum()[i] * cfa_b.firstDatum()[i];
    }
   
    the_timer.stop(4);
    cout << "\n Time spent with ConcreteFormed arrays (s) "
	 << "\n(bypassing operator()) = "
	 << the_timer.read(4) << endl;
    cout << "Result = " << result << endl;

    // bypassing firstDatum()

    double *p_cfa_a = cfa_a.firstDatum();
    double *p_cfa_b = cfa_b.firstDatum();

    the_timer.set(6);
    the_timer.start(6);

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<vec_dim; ++i) {
	p_cfa_a[i] = p_cfa_b[i] = double(i)/vec_dim;
      }
      for(Subscript i=0; i<vec_dim; ++i)
	result += p_cfa_a[i] * p_cfa_b[i];
    }
  
    the_timer.stop(6);
    cout << "\n Time spent with ConcreteFormed arrays (s) "
	 << "\n(bypassing operator()and firstDatum()) = "
	 << the_timer.read(6) << endl;
    cout << "Result = " << result << endl;
  }

  {
    // Built in array in the heap

    double *da_a = new double[vec_dim];
    double *da_b = new double[vec_dim];
    double result;

    the_timer.set(5);
    the_timer.start(5);

    for(int iprod=0; iprod<n_prods; ++iprod) {
      result = 0.0;
      
      for(Subscript i=0; i<vec_dim; ++i) {
	da_a[i] = da_b[i] = double(i)/vec_dim;
      }
      for(Subscript i=0; i<vec_dim; ++i)
	result += da_a[i] * da_b[i];
    }

    the_timer.stop(5);
    cout << "\n Time spent with arrays from heap (s) = "
	 << the_timer.read(5) << endl;
    cout << "Result = " << result << endl;

    delete [] da_a;
    delete [] da_b;
 }
 }

  /* Best timings so far: vec_dim = 250000; n_prods = 200;

     Time spent with built in arrays (s) = 7.36
     Result = 83332.8

     Time spent with ConcreteRigid arrays (s) = 7.63
     Result = 83332.8

     Time spent with ConcreteFormed arrays (s) = 7.68
     Result = 83332.8

     Time spent with ConcreteFormed arrays (s)  
     (includes memory allocation) = 7.68

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()) = 7.66
     Result = 83332.8

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()and firstDatum()) = 7.66
     Result = 83332.8

     Time spent with arrays from heap (s) = 7.67
     Result = 83332.8

     -------
     Best timings so far: vec_dim = 250; n_prods = 200000;

     Time spent with built in arrays (s) = 5.62
     Result = 82.834

     Time spent with ConcreteRigid arrays (s) = 5.03
     Result = 82.834

     Time spent with ConcreteFormed arrays (s) = 5.03
     Result = 82.834

     Time spent with ConcreteFormed arrays (s)  
     (includes memory allocation) = 5.03

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()) = 5.08
     Result = 82.834

     Time spent with ConcreteFormed arrays (s) 
     (bypassing operator()and firstDatum()) = 5.03
     Result = 82.834

     Time spent with arrays from heap (s) = 5.03
     Result = 82.834
  */
#endif 

#if TEST2 || TEST_ALL

  {
  cout << "\nTest/timing for operator=(const T& rhs)" << endl;

  const int vec_dim = 250;
  const unsigned int n_equal = 2000000;
    
  {
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 0.0;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
  }
  {
    // Built in array in the heap

    double *da_a = new double[vec_dim];
    double *da_b = new double[vec_dim];
    double value = 0.0;

    the_timer.set(1);
    the_timer.start(1);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	da_a[i] = value;
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

    ConcreteRigidArray1d<double, vec_dim> cra_a, cra_b;
    double value = 0.0;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteRigid arrays (s) = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_a[i] != value ) {
	cout << "error: expected " << value << " found " << cra_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  {
    //ConcreteFormedArray1d<double>  cfa_a(vec_dim), cfa_b(vec_dim);
    ConcreteFortranArray1d<double>  cfa_a(vec_dim), cfa_b(vec_dim);
   
    the_timer.set(3);
    the_timer.start(3);
    double value = 0.0;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cfa_a = value;
    }

    the_timer.stop(3);
    cout << "\n Time spent with ConcreteFormed arrays (s) = "
	 << the_timer.read(3) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cfa_a[i] != value ) { 
	cout << "error: expected " << value << " found " << cfa_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  }

  /* Sample runs:
     vec_dim = 250000; n_equal = 400;

     Time spent with built in arrays (s) = 4.52

     Time spent with arrays from heap (s) = 4.68

     Time spent with ConcreteRigid arrays (s) = 4.66

     Time spent with ConcreteFormed arrays (s) = 4.68

     ---
     Time spent with built in arrays (s) = 4.66

     Time spent with arrays from heap (s) = 4.68

     Time spent with ConcreteRigid arrays (s) = 4.67

     Time spent with ConcreteFormed arrays (s) = 4.67

     -----
     vec_dim = 250; n_equal = 2000000;

     Time spent with built in arrays (s) = 2.29

     Time spent with arrays from heap (s) = 5.64

     Time spent with ConcreteRigid arrays (s) = 3.41

     Time spent with ConcreteFormed arrays (s) = 6.88

   */
#endif

#if TEST3 || TEST_ALL

  {
  cout << "\nTest/timing for operator=(const Array& rhs)" << endl;

  const int vec_dim = 250;
  const unsigned int n_equal = 2000000;
  {
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 0.0;

    for(int i=0; i<vec_dim; ++i)
      bia_b[i] = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i)
	bia_a[i] = bia_b[i];
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
  }
  {
    // Built in array in the heap

    double *da_a = new double[vec_dim];
    double *da_b = new double[vec_dim];
    double value = 0.0;

    the_timer.set(1);
    the_timer.start(1);

    for(int i=0; i<vec_dim; ++i)
      da_b[i] = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	da_a[i] = da_b[i];
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

    ConcreteRigidArray1d<double, vec_dim> cra_a, cra_b;
    double value = 0.0;

    cra_b = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = cra_b;
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteRigid arrays (s) = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_a[i] != value ) { 
	cout << "error: expected " << value << " found " << cra_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  {
    //ConcreteFormedArray1d<double>  cfa_a(vec_dim), cfa_b(vec_dim);
    ConcreteFortranArray1d<double>  cfa_a(vec_dim), cfa_b(vec_dim);
   
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

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cfa_a[i] != value ) { 
	cout << "error: expected " << value << " found " << cfa_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  }

  /*
    Test/timing for operator=(const Array& rhs)
    const int vec_dim = 250;
    const unsigned int n_equal = 2000000;

    Time spent with built in arrays (s) = 3.43

    Time spent with arrays from heap (s) = 7.21

    Time spent with ConcreteRigid arrays (s) = 5.64

    Time spent with ConcreteFormed arrays (s) = 7.06
  */

#endif 

  return EXIT_SUCCESS;

}
// ***************************************************
// ***************************************************


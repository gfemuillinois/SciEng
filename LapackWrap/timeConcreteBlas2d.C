//
// Timing and testing ConcreteBlas2d

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>

#include "timer.h"
#include "ConcreteBlas2d.h"
#include "TransposedConcreteBlas2d.h"

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL  0

#define TEST1 0  // Test/timing for operator ++ -- - (negate)

#define TEST2 0  // Test/timing for operators += -=(const Array& rhs)

#define TEST3 0  // Test/timing for operators *= (const Array& rhs)

#define TEST4 0  // Test/timing for operators += -=(const T& rhs)

#define TEST5 0  // Test/timing for operators *= /=(const T& rhs)

#define TEST6 0  // Test/timing for operators * / (const T& rhs)
                 // Test/timing for XmultScalar/scale

#define TEST7 0  // Test/timing for operators + - (const T& rhs)
                 // Test/timing for XplusScalar/add

#define TEST8 0  // Test/Timing for operators + - (const Array& lhs, const Array& rhs)
                 // Test/timing for XplusY/add XminusY/sub

#define TEST9 1  // Test/Timing for operators * (const Array& lhs, const Array& rhs)
                 // Test/timing for mult, Trans * Trans, mult(trans, trans)
                 // Test/timing for array * Trans, mult( array, trans)

#define TEST10 0 // Test/Timing for operators == != (const Array& rhs)

#define TEST11 0 // Test/Timing for c = A * b ( Matrix * vector )
                 // Test/Timing for mult

#if TEST1 || TEST_ALL
  cout << "\nTest/timing for operator ++ -- - (negate) " << endl;

  {
    const int mat_dim = 25;
    const int n_oper = 200000;  

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;

    for(int iop=0; iop<n_oper; ++iop) {
 
      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j]++;

      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  ++bia_a[i][j];

      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j]--;     

      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  --bia_a[i][j];
      
      for(int i=0; i<mat_dim; ++i)
	for(int j=0; j<mat_dim; ++j)
	  -bia_a[i][j];
    }

    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;

    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	if ( bia_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << bia_a[i][j] << endl;
	  return EXIT_FAILURE;;
	}

    // -----------------------------

    the_timer.set(1);
    the_timer.start(1);
 
    ConcreteBlas2d<double> ra_a(mat_dim, mat_dim);

    ra_a = value;
    for(int iop=0; iop<n_oper; ++iop) {
      ra_a++;
      ++ra_a;
      ra_a--;
      --ra_a;
      -ra_a;
    }
   
    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( ra_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << ra_a[i][j] << endl;
	  return EXIT_FAILURE;;
	}
      }
    }

  }
  /*
    const int mat_dim = 25;
    const int n_oper = 200000;  

    Test/timing for operator ++ -- - (negate) 

 Time spent with built in arrays (s) = 7.05

 Time spent with ConcreteBlas2d arrays (s) = 94.49

  */
#endif

#if TEST2 || TEST_ALL
  cout << "\nTest/timing for operators += -=(const Array& rhs)" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_b[i][j] = 2*value;
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {

      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] += bia_b[i][j];
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] -= bia_b[i][j];
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	if ( bia_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << bia_a[i][j] << endl;
	  return EXIT_FAILURE;;
	}

    // ------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim);

    cra_a = value;
    cra_b = 2*value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a += cra_b;
      cra_a -= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j)
	if ( cra_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << cra_a[i][j] << endl;
	  return EXIT_FAILURE;;
	}
    }
  }
  /*
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;
 
    Test/timing for operators += -=(const Array& rhs)
    
 Time spent with built in arrays (s) = 3.32

 Time spent with ConcreteBlas2d arrays (s) = 6.06

  */
#endif

#if TEST3 || TEST_ALL
  cout << "\nTest/timing for operators *= (const Array& rhs)" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 1000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim],
      bia_c[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_b[i][j] = 2*value;
    }

    // a *= b
    for(unsigned  int equal=0; equal<n_equal; ++equal) {

      // c = a
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_c[i][j] = bia_a[i][j];
      }

      // a = c * b
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  bia_a[i][j] = 0.0;
	  for(int k=0; k<mat_dim; ++k) 
	    bia_a[i][j] += bia_c[i][k] * bia_b[k][j];
	}
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;

    // --------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim),
      cra_b(mat_dim, mat_dim);

    cra_a = value;
    cra_b = 2*value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a *= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j)
	if ( cra_a[i][j] != bia_a[i][j] ) {
	  cout << "error: expected " << bia_a[i][j] << 
	    " found " << cra_a[i][j] << endl;
	  return EXIT_FAILURE;;
	}
    }
  }
  /*
    const int mat_dim = 25;
    const unsigned int n_equal = 1000;
 
    Test/timing for operators *= (const Array& rhs)

 Time spent with built in arrays (s) = 7.28

 Time spent with ConcreteBlas2d arrays (s) = 7.31

  */
#endif

#if TEST4 || TEST_ALL
  cout << "\nTest/timing for operators += -=(const T& rhs)" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {

      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] += value;
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] -= value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	if ( bia_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << bia_a[i][j] << endl;
	  return EXIT_FAILURE;;
	}

    // -----------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim);

    cra_a = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a += value;
      cra_a -= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j)
	if ( cra_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << cra_a[i][j] << endl;
	  return EXIT_FAILURE;
	}
    }
  }
  /*
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

    Test/timing for operators += -=(const T& rhs)

    Time spent with built in arrays (s) = 3.24

    Time spent with ConcreteBlas2d arrays (s) = 5.64

  */
#endif

#if TEST5 || TEST_ALL
  cout << "\nTest/timing for operators *= /=(const T& rhs)" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] *= value;
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] /= value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i)
      for(int j=0; j<mat_dim; ++j)
	if ( bia_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << bia_a[i][j] << endl;
	  return EXIT_FAILURE;
	}

    // --------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a *= value;
      cra_a /= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j)
	if ( cra_a[i][j] != value ) {
	  cout << "error: expected " << value << 
	    " found " << cra_a[i][j] << endl;
	  return EXIT_FAILURE;
	}
    }
  }
  /*
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

    Test/timing for operators *= /=(const T& rhs)

    Time spent with built in arrays (s) = 12.24

    Time spent with ConcreteBlas2d arrays (s) = 2.27

  */
#endif

#if TEST6 || TEST_ALL
  cout << "\nTest/timing for operators * / (const T& rhs)" << endl;
  cout << "\nTest/timing for XmultScalar/scale" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim], 
      bia_c[mat_dim][mat_dim];
    double value = 10.0;
    double recp_value = 1.0/value;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_b[i][j] = bia_a[i][j] * value;
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_c[i][j] = bia_a[i][j] * recp_value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j) {
	if ( bia_b[i][j] != value*value ) {
	  cout << "error: expected " << value*value << 
	    " found " << bia_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   bia_c[i][j] != 1.0 ) {
	  cout << "error: expected " << 1.0 << 
	    " found " << bia_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // --------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_b = cra_a * value;

      cra_c = cra_a * (recp_value);
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_b[i][j] != value*value ) {
	  cout << "error: expected " << value*value << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   cra_c[i][j] != 1.0 ) {
	  cout << "error: expected " << 1.0 << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }
   // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      scale(cra_a, value, cra_b); // b = value * a

      scale(cra_a, (recp_value), cra_c ); // c = 1/value * a
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas2d arrays (s)\n"
	 << " XmultScalar/scale = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_b[i][j] != value * value ) {
	  cout << "error: expected " << value*value << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   cra_c[i][j] != 1.0 ) {
	  cout << "error: expected " << 1.0 << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

  }
  /*

  const int mat_dim = 25;
  const unsigned int n_equal = 200000;

 Time spent with built in arrays (s) = 4.9

 Time spent with ConcreteBlas2d arrays (s) = 36.93

 Time spent with ConcreteBlas2d arrays (s)
 XmultScalar/scale = 6.06

  */
#endif

#if TEST7 || TEST_ALL
  cout << "\nTest/timing for operators + - (const T& rhs)" << endl;
  cout << "\nTest/timing for XplusScalar/add" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim], 
      bia_c[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_b[i][j] = bia_a[i][j] + value;
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_c[i][j] = bia_a[i][j] - value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j) {
	if ( bia_b[i][j] != value + value ) {
	  cout << "error: expected " << value+value << 
	    " found " << bia_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   bia_c[i][j] != 0.0 ) {
	  cout << "error: expected " << 0.0 << 
	    " found " << bia_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }
    
    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      //cra_b = cra_a + value;
      cra_b = value + cra_a;  // same as cra_a + value

      cra_c = cra_a - value; // or cra_c =  cra_a + (-value);
      //cra_c = value - cra_a; // will call negate()
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_b[i][j] != value + value ) {
	  cout << "error: expected " << value+value << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   cra_c[i][j] != 0.0 ) {
	  cout << "error: expected " << 0.0 << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      add(cra_a, value, cra_b); // b = a + value

      add(cra_a, (-value), cra_c); // c = a - value

      // add(-cra_a, value, cra_c ); // c = value - a; will call negate()
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas2d arrays (s)\n"
	 << " XplusScalar/add = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_b[i][j] != value + value ) {
	  cout << "error: expected " << value+value << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   cra_c[i][j] != 0.0 ) {
	  cout << "error: expected " << 0.0 << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }
    
  }
  /*

  const int mat_dim = 25;
  const unsigned int n_equal = 200000;

  cra_b = value + cra_a;
  cra_c = cra_a - value;

Test/timing for operators + - (const T& rhs)

 Time spent with built in arrays (s) = 4.41

 Time spent with ConcreteBlas2d arrays (s) = 40.32

 Time spent with ConcreteBlas2d arrays (s)
 XplusScalar/add = 6.46

  */
#endif

#if TEST8 || TEST_ALL
  cout << "\nTest/Timing for operators + - (const Array& lhs, const Array& rhs)" << endl;
  cout << "\nTest/Timing for XplusY/add XminusY/sub" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim],
      bia_c[mat_dim][mat_dim];
    double value = 10.0;

    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j) {
	bia_a[i][j] = value;
      }
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_b[i][j] = bia_a[i][j] + bia_a[i][j];
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_c[i][j] = bia_a[i][j] - bia_a[i][j];
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j) {
	if ( bia_b[i][j] != value + value ) {
	  cout << "error: expected " << value+value << 
	    " found " << bia_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   bia_c[i][j] != 0.0 ) {
	  cout << "error: expected " << 0.0 << 
	    " found " << bia_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }
    
    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_b = cra_a + cra_a;

      cra_c = cra_a - cra_a;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_b[i][j] != value + value ) {
	  cout << "error: expected " << value+value << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   cra_c[i][j] != 0.0 ) {
	  cout << "error: expected " << 0.0 << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      // add( cra_a, cra_a, cra_b );

      add( cra_a, cra_a, cra_b ); // b = a + a

      sub( cra_a, cra_a, cra_c ); // c = a - a
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas2d arrays (s)\n"
	 << " XplusY/add XminusY/sub = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_b[i][j] != value + value ) {
	  cout << "error: expected " << value+value << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
	if (   cra_c[i][j] != 0.0 ) {
	  cout << "error: expected " << 0.0 << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

  }
  /*
Test/Timing for operators + - (const Array& lhs, const Array& rhs)

    const int mat_dim = 25;

    const unsigned int n_equal = 200000;

 Time spent with built in arrays (s) = 4.79

 Time spent with ConcreteBlas2d arrays (s) = 40.61

 Time spent with ConcreteBlas2d arrays (s)
 XplusY/add XminusY/sub = 8.72

  */
#endif

#if TEST9 || TEST_ALL
  cout << "\nTest/Timing for operators * (const Array& lhs, const Array& rhs)" << endl;
  cout << "\nTest/Timing for mult, Trans * Trans, mult(trans, trans)" << endl;
  cout << "\nTest/Timing for array * Trans, mult( array, trans)" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 10000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim],
      bia_c[mat_dim][mat_dim];
    double value = 10.0;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_b[i][j] = 2*value;
    }

    // c = a * b
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  bia_c[i][j] = 0.0;
	  for(int k=0; k<mat_dim; ++k)
	    bia_c[i][j] += bia_a[i][k] * bia_b[k][j]; 
	}
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;

    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_c = cra_a * cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_c[i][j] != bia_c[i][j] ) {
	  cout << "error: expected " << bia_c[i][j] << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // ----------------------------
    
    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      mult( cra_a, cra_b, cra_c ); // c = a * b
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas2d arrays (s)\n"
	 << " mult  = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_c[i][j] != bia_c[i][j] ) {
	  cout << "error: expected " << bia_c[i][j] << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // ----------------------------
    // TransposedConcreteBlas2d * TransposedConcreteBlas2d

    // Sanity checks:
    ConcreteBlas2d<double> cra_at(2*mat_dim, mat_dim), 
      cra_bt(mat_dim, 2*mat_dim);

    cra_c = TransposedConcreteBlas2d<double>( cra_at ) 
          * TransposedConcreteBlas2d<double>( cra_bt );

    mult( TransposedConcreteBlas2d<double>( cra_at ), 
    	  TransposedConcreteBlas2d<double>( cra_bt ), 
    	  cra_c ); // C = A^t * B^t


    the_timer.set(3);
    the_timer.start(3);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_c = TransposedConcreteBlas2d<double>( cra_a ) 
	* TransposedConcreteBlas2d<double>( cra_b );
    }

    the_timer.stop(3);
    cout << "\n Time spent with Trans * Trans arrays (s) = "
	 << the_timer.read(3) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_c[i][j] != bia_c[i][j] ) {
	  cout << "error: expected " << bia_c[i][j] << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }
    // ----------------------------
    
    the_timer.set(4);
    the_timer.start(4);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      mult( TransposedConcreteBlas2d<double>( cra_a ), 
	    TransposedConcreteBlas2d<double>( cra_b ), 
	    cra_c ); // C = A^t * B^t
    }

    the_timer.stop(4);
    cout << "\n Time spent with Trans * Trans arrays (s)\n"
	 << " mult  = "
	 << the_timer.read(4) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_c[i][j] != bia_c[i][j] ) {
	  cout << "error: expected " << bia_c[i][j] << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // ----------------------------
    // ConcreteBlas2d * TransposedConcreteBlas2d

    // Sanity checks:
    ConcreteBlas2d<double> cra_bt1(2*mat_dim, mat_dim), cra_ct1(mat_dim, 2*mat_dim);

    cra_ct1 =  cra_a * TransposedConcreteBlas2d<double>( cra_bt1 );

    mult( cra_a, 
    	  TransposedConcreteBlas2d<double>( cra_bt1 ), 
    	  cra_ct1 ); // C = A * B^t


    the_timer.set(5);
    the_timer.start(5);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_c = cra_a * TransposedConcreteBlas2d<double>( cra_b );
    }

    the_timer.stop(5);
    cout << "\n Time spent with array  * Trans arrays (s) = "
	 << the_timer.read(5) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_c[i][j] != bia_c[i][j] ) {
	  cout << "error: expected " << bia_c[i][j] << 
	    " found " << cra_b[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }
    // ----------------------------

    the_timer.set(6);
    the_timer.start(6);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      mult( cra_a, 
	    TransposedConcreteBlas2d<double>( cra_b ), 
	    cra_c ); // C = A * B^t
    }

    the_timer.stop(6);
    cout << "\n Time spent with array * Trans arrays (s)\n"
	 << " mult  = "
	 << the_timer.read(6) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( cra_c[i][j] != bia_c[i][j] ) {
	  cout << "error: expected " << bia_c[i][j] << 
	    " found " << cra_c[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

    // ----------------------------    


    // ----------------------------
    // TransposedConcreteBlas2d * ConcreteBlas2d

    // Sanity checks:
    ConcreteBlas2d<double> cra_At(mat_dim, 2*mat_dim), cra_C(2*mat_dim, mat_dim);

    cra_C = TransposedConcreteBlas2d<double>( cra_At ) * cra_b;
    
    mult( TransposedConcreteBlas2d<double>( cra_At ), cra_b,
    	  cra_C ); // C = A^t * B


    // ----------------------------
    // TransposedConcreteBlas2d * ConcreteBlas1d

    // Sanity checks:
    ConcreteBlas1d<double> b(mat_dim), c(2*mat_dim);

    c = TransposedConcreteBlas2d<double>( cra_At ) * b;
    
    mult( TransposedConcreteBlas2d<double>( cra_At ), b,
    	  c ); // c = A^t * b

  }

  /*

Test/Timing for operators * (const Array& lhs, const Array& rhs)

 Time spent with built in arrays (s) = 4.2

 Time spent with ConcreteBlas2d arrays (s) = 5.26

 Time spent with ConcreteBlas2d arrays (s)
 mult  = 4.15

 Time spent with Trans * Trans arrays (s) = 6.38

 Time spent with Trans * Trans arrays (s)
 mult  = 5.76

 Time spent with array  * Trans arrays (s) = 4.48

 Time spent with array * Trans arrays (s)
 mult  = 3.82

  */
#endif

#if TEST10 || TEST_ALL
  cout << "\nTest/Timing for operators == != (const Array& rhs)" << endl;
  {
    const int mat_dim = 25;
    const unsigned int n_equal = 600000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim][mat_dim],
      bia_c[mat_dim][mat_dim];
    double value = 10.0;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j) {
	bia_a[i][j] = value;
	bia_b[i][j] = value;
	bia_c[i][j] = value + 1.;
      }
    }

    bool a_eq_b = true;
    bool a_eq_c = true;
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  if ( bia_b[i][j] != bia_a[i][j] ) {
	    a_eq_b = false;
	    break;
	  }
	}
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j) {
	  if ( bia_c[i][j] != bia_a[i][j] ) {
	    a_eq_c = false;
	    break;
	  }
	}
      }
    }

    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    cout << "a_eq_b = " << a_eq_b << endl;
    cout << "a_eq_c = " << a_eq_c << endl;

    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    cra_b = value;
    cra_c = (value + 1.);

    a_eq_b = false;
    a_eq_c = true;

    /*
    cout << int(cra_a == cra_b) << endl;
    cout << int(cra_a != cra_c) << endl;
    */
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      if ( cra_a == cra_b )
	a_eq_b = true;

      if ( cra_a != cra_c )
	a_eq_c = false;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;
    cout << "a_eq_b = " << a_eq_b << endl;
    cout << "a_eq_c = " << a_eq_c << endl;

    // ----------------------------
  }
  /*
    const int mat_dim = 25;
    const unsigned int n_equal = 600000;

Test/Timing for operators == != (const Array& rhs)

 Time spent with built in arrays (s) = 9.04
a_eq_b = 1
a_eq_c = 0

 Time spent with ConcreteBlas2d arrays (s) = 8.71
a_eq_b = 1
a_eq_c = 0

  */
#endif

#if TEST11 || TEST_ALL
  cout << "\nTest/Timing for c = A * b" << endl;
  cout << "\nTest/Timing for mult" << endl;

  {
    const int mat_dim = 25;
    const unsigned int n_equal = 600000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[mat_dim][mat_dim], bia_b[mat_dim],
      bia_c[mat_dim];
    double value = 10.0;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j)
	bia_a[i][j] = value;
    }
    for(int i=0; i<mat_dim; ++i) {
	bia_b[i] = 2*value;
    }

    // c = A * b
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<mat_dim; ++i) {
	bia_c[i] = 0.0;
	for(int j=0; j<mat_dim; ++j) {
	  bia_c[i] += bia_a[i][j] * bia_b[j]; 
	}
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;

    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas2d<double> cra_a(mat_dim, mat_dim); 
    ConcreteBlas1d<double> cra_b(mat_dim), cra_c(mat_dim);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_c = cra_a * cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      if ( cra_c[i] != bia_c[i] ) {
	cout << "error: expected " << bia_c[i] << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
    }

    // ----------------------------
    
    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;
    cra_b = (2*value);
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      mult( cra_a, cra_b, cra_c ); // c = a * b
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas2d arrays (s)\n"
	 << " mult  = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      if ( cra_c[i] != bia_c[i] ) {
	cout << "error: expected " << bia_c[i] << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }
    
  }
  /*

Test/Timing for c = A * b

 Time spent with built in arrays (s) = 8.15

 Time spent with ConcreteBlas2d arrays (s) = 10.4

 Time spent with ConcreteBlas2d arrays (s)
 mult  = 9.04

  */
#endif

  return EXIT_SUCCESS;
}
// ***************************************************
// ***************************************************

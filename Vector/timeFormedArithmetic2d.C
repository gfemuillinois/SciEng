//
// Timing and testing FormedArithmetic2d

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>

#include "timer.h"
#include "FormedArithmetic.h"

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL 1

#define TEST1 1  // Test/timing for operator ++ -- - (negate)

#define TEST2 1  // Test/timing for operators += -=(const Array& rhs)

#define TEST3 1  // Test/timing for operators *= /=(const Array& rhs)

#define TEST4 1  // Test/timing for operators += -=(const T& rhs)

#define TEST5 1  // Test/timing for operators *= /=(const T& rhs)

#define TEST6 1  // Test/timing for operators * / (const T& rhs)
                 // Test/timing for XmultScalar/scale

#define TEST7 1  // Test/timing for operators + - (const T& rhs)
                 // Test/timing for XplusScalar/add

#define TEST8 1  // Test/Timing for operators + - (const Array& lhs, const Array& rhs)
                 // Test/Timing for XplusY/add XminusY/sub

#define TEST9 1  // Test/Timing for operators * / (const Array& lhs, const Array& rhs)
                 // Test/Timing for XtimesY/distMult XdivY/distDiv

#define TEST10 1 // Test/Timing for operators == != (const Array& rhs)

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
	  return EXIT_FAILURE;
	}
    // -----------------------------

    the_timer.set(1);
    the_timer.start(1);
 
    FormedArithmetic2d<double> ra_a(mat_dim, mat_dim);

    ra_a = value;
    for(int iop=0; iop<n_oper; ++iop) {
      ra_a++;
      ++ra_a;
      ra_a--;
      --ra_a;
      -ra_a;
    }
   
    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<mat_dim; ++i) {
      for(Subscript j=0; j<mat_dim; ++j) {
	if ( ra_a[i][j] != value ) { 
	  cout << "error: expected " << value << 
	    " found " << ra_a[i][j] << endl;
	  return EXIT_FAILURE;
	}
      }
    }

  }
  /*
    const int mat_dim = 25;
    const int n_oper = 200000;  

    Test/timing for operator ++ -- - (negate) 

 Time spent with built in arrays (s) = 9.73

 Time spent with FormedArithmetic2d arrays (s) = 89.23

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
	  return EXIT_FAILURE;
	}

    // ------------------------------

    the_timer.set(1);
    the_timer.start(1);

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim);

    cra_a = value;
    cra_b = 2*value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a += cra_b;
      cra_a -= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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
 
    Test/timing for operators += -=(const Array& rhs)
    
 Time spent with built in arrays (s) = 4.13

 Time spent with FormedArithmetic2d arrays (s) = 6.25

  */
#endif

#if TEST3 || TEST_ALL
  cout << "\nTest/timing for operators *= /=(const Array& rhs)" << endl;

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
	  bia_a[i][j] *= bia_b[i][j];
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_a[i][j] /= bia_b[i][j];
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

    // --------------------------

    the_timer.set(1);
    the_timer.start(1);

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim),
      cra_b(mat_dim, mat_dim);

    cra_a = value;
    cra_b = 2*value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a *= cra_b;
      cra_a /= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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
 
    Test/timing for operators *= /=(const Array& rhs)

 Time spent with built in arrays (s) = 13.61

 Time spent with FormedArithmetic2d arrays (s) = 13.18

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
	  return EXIT_FAILURE;
	}

    // -----------------------------------

    the_timer.set(1);
    the_timer.start(1);

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim);

    cra_a = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a += value;
      cra_a -= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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

 Time spent with built in arrays (s) = 4.84

 Time spent with FormedArithmetic2d arrays (s) = 8.6

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

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a *= value;
      cra_a /= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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

 Time spent with built in arrays (s) = 13.18

 Time spent with FormedArithmetic2d arrays (s) = 15.81

  */
#endif

#if TEST6 || TEST_ALL
  cout << "\nTest/timing for operators * / (const T& rhs)";
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

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_b = cra_a * value;

      cra_c = cra_a * (recp_value);
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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
    cout << "\n Time spent with FormedArithmetic2d arrays (s)\n"
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

 Time spent with built in arrays (s) = 4.43

 Time spent with FormedArithmetic2d arrays (s) = 43.24

 Time spent with FormedArithmetic2d arrays (s)
 XmultScalar/scale = 5.96

  */
#endif

#if TEST7 || TEST_ALL
  cout << "\nTest/timing for operators + - (const T& rhs)";
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

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      //cra_b = cra_a + value;
      cra_b = value + cra_a;  // same as cra_a + value

      cra_c = cra_a - value; // or cra_c =  cra_a + (-value);
      //cra_c = value - cra_a; // will call negate()
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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
    cout << "\n Time spent with FormedArithmetic2d arrays (s)\n"
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

 Time spent with built in arrays (s) = 4.04

 Time spent with FormedArithmetic2d arrays (s) = 43.04

 Time spent with FormedArithmetic2d arrays (s)
 XplusScalar/add = 6.39

  */
#endif

#if TEST8 || TEST_ALL
  cout << "\nTest/Timing for operators + - (const Array& lhs, const Array& rhs)";
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

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_b = cra_a + cra_a;

      cra_c = cra_a - cra_a;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
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
    cout << "\n Time spent with FormedArithmetic2d arrays (s)\n"
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

 Time spent with built in arrays (s) = 3.9

 Time spent with FormedArithmetic2d arrays (s) = 41.47

 Time spent with FormedArithmetic2d arrays (s)
 XplusY/add XminusY/sub = 6.5

  */
#endif

#if TEST9 || TEST_ALL
  cout << "\nTest/Timing for operators * / (const Array& lhs, const Array& rhs)";
  cout << "\nTest/Timing for XtimesY/distMult XdivY/distDiv" << endl;

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
	  bia_b[i][j] = bia_a[i][j] * bia_a[i][j];
      }
      for(int i=0; i<mat_dim; ++i) {
	for(int j=0; j<mat_dim; ++j)
	  bia_c[i][j] = bia_a[i][j] / bia_a[i][j];
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<mat_dim; ++i) {
      for(int j=0; j<mat_dim; ++j) {
	if ( bia_b[i][j] != value * value ) {
	  cout << "error: expected " << value * value << 
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
    
    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim), 
      cra_b(mat_dim, mat_dim), cra_c(mat_dim, mat_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_b = cra_a * cra_a;

      cra_c = cra_a / cra_a;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
	 << the_timer.read(1) << endl;

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

    // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      distMult( cra_a, cra_a, cra_b ); // b = a * a

      distDiv(  cra_a, cra_a, cra_c ); // c = a / a
    }

    the_timer.stop(2);
    cout << "\n Time spent with FormedArithmetic2d arrays (s)\n"
	 << " XtimesY/distMult XdivY/distDiv = "
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

Test/Timing for operators * / (const Array& lhs, const Array& rhs)

    const int mat_dim = 25;
    const unsigned int n_equal = 200000;

 Time spent with built in arrays (s) = 13.46

 Time spent with FormedArithmetic2d arrays (s) = 46.73

 Time spent with FormedArithmetic2d arrays (s)
 XtimesY/distMult XdivY/distDiv = 13.65

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

    FormedArithmetic2d<double> cra_a(mat_dim, mat_dim), 
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
    cout << "\n Time spent with FormedArithmetic2d arrays (s) = "
	 << the_timer.read(1) << endl;
    cout << "a_eq_b = " << a_eq_b << endl;
    cout << "a_eq_c = " << a_eq_c << endl;

    // ----------------------------
  }
  /*
    const int mat_dim = 25;
    const unsigned int n_equal = 600000;

Test/Timing for operators == != (const Array& rhs)

 Time spent with built in arrays (s) = 9.09
a_eq_b = 1
a_eq_c = 0

 Time spent with FormedArithmetic2d arrays (s) = 8.7
a_eq_b = 1
a_eq_c = 0

  */
#endif

  return EXIT_SUCCESS;
}
// ***************************************************
// ***************************************************


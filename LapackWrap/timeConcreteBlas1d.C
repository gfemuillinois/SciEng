//
// Timing and testing ConcreteBlas1d

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include <math.h>

#include "timer.h"
#include "ConcreteBlas1d.h"

using std::cout;
using std::endl;

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL  1

#define TEST1 1  // Test/timing for operator - (negate)

#define TEST2 0  // Test/timing for operators += -=(const Array& rhs)

                 // These operators are NOT available for ConcreteBlas1d
#define TEST3 0  // Test/timing for operators *= /=(const Array& rhs)

#define TEST4 0  // Test/timing for operators += -=(const T& rhs)

#define TEST5 0  // Test/timing for operators *= /=(const T& rhs)

#define TEST6 0  // Test/timing for operators * / (const T& rhs)
                 // Test/timing for XmultScalar/scale/mult

#define TEST7 0  // Test/timing for operators + - (const T& rhs)
                 // Test/timing for XplusScalar/add 

#define TEST8 0  // Test/Timing for operators + - (const Array& rhs0, const Array& rhs1)
                 // Test/Timing for XplusY/add XminusY/sub 

                 // These operators are NOT available for ConcreteBlas1d
#define TEST9 0  // Test/Timing for operators * / (const Array& rhs0, const Array& rhs1)

#define TEST10 0 // Test/Timing for operators == != (const Array& rhs)

#define TEST11 0 // Test/Timing for Metric space category
                 // dot norm cosAngle and angle

#if TEST1 || TEST_ALL
  cout << "\n Test/timing for operator - (negate) " << endl;

  {
    const int vec_dim = 250;
    const int n_oper = 600000;  

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim];
    double value = 10.0;

    for(int i=0; i<vec_dim; ++i)
      bia_a[i] = value;

    for(int iop=0; iop<n_oper; ++iop) {
      for(int i=0; i<vec_dim; ++i)
	-bia_a[i];
    }

    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;

    for(int i=0; i<vec_dim; ++i)
      if ( bia_a[i] != value ) {
	cout << "error: expected " << value << 
	  " found " << bia_a[i] << endl;
	return EXIT_FAILURE;
      }

    // -----------------------------

    the_timer.set(1);
    the_timer.start(1);
 
    ConcreteBlas1d<double> ra_a(vec_dim);

    ra_a = value;
    for(int iop=0; iop<n_oper; ++iop) {
      -ra_a;
    }
   
    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( ra_a[i] != value ) {
	cout << "error: expected " << value << 
	  " found " << ra_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  /*
    const int vec_dim = 250;
    const int n_oper = 600000;  

 Test/timing for operator - (negate) 

 Time spent with built in arrays (s) = 0.69

 Time spent with ConcreteBlas1d arrays (s) = 15.56

  */

#endif

#if TEST2 || TEST_ALL
  cout << "\nTest/timing for operators += -=(const Array& rhs)" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 10.0;

    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
    }
    for(int i=0; i<vec_dim; ++i) {
      bia_b[i] = 2*value;
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] += bia_b[i];
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] -= bia_b[i];
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i)
      if ( bia_a[i] != value ) {
	cout << "error: expected " << value << 
	  " found " << bia_a[i] << endl;
	return EXIT_FAILURE;
      }

    // ------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim), cra_b(vec_dim);

    cra_a = value;
    cra_b = 2*value;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a += cra_b;
      cra_a -= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_a[i] != value ) { 
	cout << "error: expected " << value << 
	  " found " << cra_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  /*
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;
 
    Test/timing for operators += -=(const Array& rhs)
    
    Time spent with built in arrays (s) = 1.24

    Time spent with ConcreteBlas1d arrays (s) = 2.47

  */
#endif


#if TEST4 || TEST_ALL
  cout << "\nTest/timing for operators += -=(const T& rhs)" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 10.0;

    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
    }
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] += value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] -= value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i)
      if ( bia_a[i] != value ) {
	cout << "error: expected " << value << 
	  " found " << bia_a[i] << endl;
	return EXIT_FAILURE;
      }

    // -----------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a += value;
      cra_a -= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_a[i] != value ) { 
	cout << "error: expected " << value << 
	  " found " << cra_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  /*
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    Test/timing for operators += -=(const T& rhs)

    Time spent with built in arrays (s) = 1.35

    Time spent with ConcreteBlas1d arrays (s) = 2.29

  */
#endif

#if TEST5 || TEST_ALL
  cout << "\nTest/timing for operators *= /=(const T& rhs)" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim];
    double value = 10.0;
    
    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
    }
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] *= value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] /= value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i)
      if ( bia_a[i] != value ) {
	cout << "error: expected " << value << 
	  " found " << bia_a[i] << endl;
	return EXIT_FAILURE;
      }

    // --------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a *= value;
      cra_a /= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_a[i] != value ) { 
	cout << "error: expected " << value << 
	  " found " << cra_a[i] << endl;
	return EXIT_FAILURE;
      }
    }
  }
  /*
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

 Test/timing for operators *= /=(const T& rhs)

 Time spent with built in arrays (s) = 4.87

 Time spent with FormedArithmetic1d arrays (s) = 5.49

  */
#endif

#if TEST6 || TEST_ALL
  cout << "\nTest/timing for operators * / (const T& rhs)";
  cout << "\nTest/timing for XmultScalar/scale/mult" << endl;
  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim], bia_c[vec_dim];
    double value = 10.0;
    double recp_value = 1.0/value;

    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_b[i] = bia_a[i] * value;
      }
      for(int i=0; i<vec_dim; ++i) {
	//bia_c[i] = bia_a[i] / value;
	bia_c[i] = bia_a[i] * recp_value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i) {
      if ( bia_b[i] != value*value ) {
	cout << "error: expected " << value*value << 
	  " found " << bia_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   bia_c[i] != 1.0 ) {
	cout << "error: expected " << 1.0 << 
	  " found " << bia_c[i] << endl;
	return EXIT_FAILURE;
      }
    }

    // --------------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      cra_b = cra_a * value;
      //cra_b = value * cra_a;  // same as cra_a * value

      //cra_c = cra_a / value;    
      // or do: 
      cra_c = cra_a * (recp_value);

      //cra_c = value / cra_a;  // slower then cra_a / value
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_b[i] != value*value ) {
	cout << "error: expected " << value*value << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   cra_c[i] != 1.0 ) {
	cout << "error: expected " << 1.0 << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }
   // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

#define TEST_SCALE_MULT 1
    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

#if TEST_SCALE_MULT
      // scale == mult
      scale(cra_a, value, cra_b); // b = a * value
      mult(cra_a, (recp_value), cra_c ); // c = a / value
#else
      XmultScalar( cra_b, cra_a, value );  // b = a * value
      XmultScalar( cra_c, cra_a, (recp_value) );  // c = a / value
#endif
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas1d arrays (s)\n"
	 << " using XmultScalar/scale/mult = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_b[i] != value * value ) {
	cout << "error: expected " << value*value << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   cra_c[i] != 1.0 ) {
	cout << "error: expected " << 1.0 << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }

  }
  /*

  const int vec_dim = 250;
  const unsigned int n_equal = 200000;

 Using  * (recp_value)

 Time spent with built in arrays (s) = 1.38

 Time spent with ConcreteBlas1d arrays (s) = 7.07

 Time spent with ConcreteBlas1d arrays (s)
 XmultScalar/mult = 2.1

  */
#endif

#if TEST7 || TEST_ALL
  cout << "\nTest/timing for operators + - (const T& rhs)";
  cout << "\nTest/timing for XplusScalar/add" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim], bia_c[vec_dim];
    double value = 10.0;

    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
    }
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_b[i] = bia_a[i] + value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_c[i] = bia_a[i] - value;
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i) {
      if ( bia_b[i] != value + value ) {
	cout << "error: expected " << value+value << 
	  " found " << bia_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   bia_c[i] != 0.0 ) {
	cout << "error: expected " << 0.0 << 
	  " found " << bia_c[i] << endl;
	return EXIT_FAILURE;
      }
    }
    
    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {
      
      //cra_b = cra_a + value;
      cra_b = value + cra_a;  // same as cra_a + value

      cra_c = cra_a - value; // or cra_c =  cra_a + (-value);
      //cra_c = value - cra_a; // will call negate()
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_b[i] != value + value ) {
	cout << "error: expected " << value+value << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   cra_c[i] != 0.0 ) {
	cout << "error: expected " << 0.0 << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }

    // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

#define TEST_ADD 1
    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

#if TEST_ADD
      add(cra_a, value, cra_b); // b = a + value
      add(cra_a, (-value), cra_c ); // c = a - value
#else
      XplusScalar( cra_b, cra_a, value );  // b = a + value
      XplusScalar( cra_c, cra_a, (-value) );  // c = a - value
#endif

      // XplusScalar(cra_c, -cra_a, value ); // c = value - a; will call negate()
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas1d arrays (s)\n"
	 << " XplusScalar/add = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_b[i] != value + value ) {
	cout << "error: expected " << value+value << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   cra_c[i] != 0.0 ) {
	cout << "error: expected " << 0.0 << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }

  }
  /*

  const int vec_dim = 250;
  const unsigned int n_equal = 200000;

  cra_b = cra_a + value;
  cra_c = cra_a - value;

 Time spent with built in arrays (s) = 1.25

 Time spent with ConcreteBlas1d arrays (s) = 7.03

 Time spent with ConcreteBlas1d arrays (s)
 XplusScalar/add = 2.51

  */
#endif

#if TEST8 || TEST_ALL
  cout << "\nTest/Timing for operators + - (const Array& rhs0, const Array& rhs1)";
  cout << "\nTest/Timing for XplusY/add XminusY/sub" << endl;
  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim], bia_c[vec_dim];
    double value = 10.0;
    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
    }

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_b[i] = bia_a[i] + bia_a[i];
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_c[i] = bia_a[i] - bia_a[i];
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i) {
      if ( bia_b[i] != value + value ) {
	cout << "error: expected " << value+value << 
	  " found " << bia_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   bia_c[i] != 0.0 ) {
	cout << "error: expected " << 0.0 << 
	  " found " << bia_c[i] << endl;
	return EXIT_FAILURE;
      }
    }
    
    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      cra_b = cra_a + cra_a;

      cra_c = cra_a - cra_a;
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_b[i] != value + value ) {
	cout << "error: expected " << value+value << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   cra_c[i] != 0.0 ) {
	cout << "error: expected " << 0.0 << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }

    // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

#define TEST_ADD_SUB 1
    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

#if TEST_ADD_SUB
      add( cra_a, cra_a, cra_b ); // b = a + a

      sub( cra_a, cra_a, cra_c ); // c = a - a
#else
      XplusY( cra_b, cra_a, cra_a);  // b = a + a

      XminusY( cra_c, cra_a, cra_a);  // c = a - a 
#endif
    }

    the_timer.stop(2);
    cout << "\n Time spent with ConcreteBlas1d arrays (s)\n"
	 << " XplusY/add XminusY/sub = "
	 << the_timer.read(2) << endl;

    for(Subscript i=0; i<vec_dim; ++i) {
      if ( cra_b[i] != value + value ) {
	cout << "error: expected " << value+value << 
	  " found " << cra_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   cra_c[i] != 0.0 ) {
	cout << "error: expected " << 0.0 << 
	  " found " << cra_c[i] << endl;
	return EXIT_FAILURE;
      }
    }

  }
  /*
Test/Timing for operators + - (const Array& lhs, const Array& rhs)

    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    Time spent with built in arrays (s) = 0.91

    Time spent with ConcreteBlas1d arrays (s) = 7.16

    Time spent with ConcreteBlas1d arrays (s)
    XplusY/add XminusY/sub = 2.34

  */
#endif

#if TEST10 || TEST_ALL
  cout << "\nTest/Timing for operators == != (const Array& rhs)" << endl;
  {
    const int vec_dim = 250;
    const unsigned int n_equal = 600000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim], bia_c[vec_dim];
    double value = 10.0;
    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
      bia_b[i] = value;
      bia_c[i] = value + 1.;
    }

    bool a_eq_b = true;
    bool a_eq_c = true;
    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	if ( bia_b[i] != bia_a[i] ) {
	  a_eq_b = false;
	  break;
	}
      }
      for(int i=0; i<vec_dim; ++i) {
	if ( bia_c[i] != bia_a[i] ) {
	  a_eq_c = false;
	  break;
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

    ConcreteBlas1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

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
    cout << "\n Time spent with ConcreteBlas1d arrays using operators (s) = "
	 << the_timer.read(1) << endl;
    cout << "a_eq_b = " << a_eq_b << endl;
    cout << "a_eq_c = " << a_eq_c << endl;

    // ----------------------------
  }
  /*
    const int vec_dim = 250;
    const unsigned int n_equal = 600000;

Test/Timing for operators == != (const Array& rhs)

 Time spent with built in arrays (s) = 2.71
a_eq_b = 1
a_eq_c = 0

 Time spent with ConcreteBlas1d arrays (s) = 3.21
a_eq_b = 1
a_eq_c = 0

  */
#endif

#if TEST11 || TEST_ALL
  cout << "\nTest/Timing for dot(const Array& rhs)" ;
  cout << "\nnorm cosAngle and angle" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 300000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 0.1, inner, inner_a, inner_b;

    for(int i=0; i<vec_dim; ++i) {
      bia_a[i] = value;
      bia_b[i] = value;
    }
    bia_b[0] = 3.0;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      inner = inner_a = inner_b = 0.0;
      for(int i=0; i<vec_dim; ++i) {
	inner += bia_a[i]*bia_b[i];
	inner_a += bia_a[i]*bia_a[i];
	inner_b += bia_b[i]*bia_b[i];
      }
    }

    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    
    cout << setiosflags( std::ios::showpoint );
    cout << std::setprecision(15);

    cout << "inner_a_b = " << inner << endl;
    cout << "inner_a = " << inner_a << endl;
    cout << "inner_b = " << inner_b << endl;
    cout << "norm_a = " << sqrt(inner_a) << endl;
    cout << "norm_b = " << sqrt(inner_b) << endl;
    
    double cos_a_b = inner/( sqrt(inner_a) * sqrt(inner_b) );
    cout << "cos_a_b = " << cos_a_b << endl;
    double angle = acos( cos_a_b );
    cout << "Angle_a_b = " <<  angle << endl;
    

    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    ConcreteBlas1d<double> cra_a(vec_dim), cra_b(vec_dim);

    cra_a = value;
    cra_b = value;
    cra_b(0) = 3.0;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      inner = cra_a.dot(cra_b);

      inner_a = cra_a.dot(cra_a);
      inner_b = cra_b.dot(cra_b);

      //    inner_a = dot(cra_a, cra_a);  // call dot friend function of
      //    inner_b = dot(cra_b, cra_b);  // MetricSpaceCategory
 
    }

    the_timer.stop(1);
    cout << "\n Time spent with ConcreteBlas1d arrays (s) = "
	 << the_timer.read(1) << endl;
    {
    cout << "inner_a_b = " << inner << endl;
    cout << "inner_a = " << inner_a << endl;
    cout << "inner_b = " << inner_b << endl;
    cout << "norm_a = " << cra_a.norm() << endl;
    cout << "norm_b = " << cra_b.norm() << endl;
    
    cout << "cos_a_b = " << cra_a.cosAngle( cra_b ) << endl;
    cout << "Angle_a_b = " << cra_a.angle( cra_b ) << endl;

    cout << "\nacos(1.0) = " << acos(1.0) << endl;
    }

    // ----------------------------
  }
  /*
    const int vec_dim = 250;
    const unsigned int n_equal = 300000;

Test/Timing for dot(const Array& rhs)

 Time spent with built in arrays (s) = 2.26
inner_a_b = 2.78999999999998
inner_a = 2.49999999999999
inner_b = 11.4899999999999
norm_a = 1.58113883008419
norm_b = 3.38969025133565
cos_a_b = 0.520564064424075
Angle_a_b = 1.02328487483649

 Time spent with ConcreteBlas1d arrays (s) = 2.85000000000000
inner_a_b = 2.79000000000000
inner_a = 2.50000000000000
inner_b = 11.4900000000000
norm_a = 1.58113883008419
norm_b = 3.38969025133566
cos_a_b = 0.520564064424075
Angle_a_b = 1.02328487483649

acos(1.0) = 0.00000000000000

  */
#endif



  return 0;
}
// ***************************************************
// ***************************************************


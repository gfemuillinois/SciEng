//
// Timing and testing FormedArithmetic1d

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>

#include "timer.h"
#include "FormedArithmetic.h"

using std::cout;
using std::endl;

Timer  the_timer(10);	// 10 clocks

int main() {

#define TEST_ALL 1

#define TEST1 1  // Test/timing for operator ++ -- - (negate)

#define TEST2 1  // Test/timing for operators += -=(const Array& rhs)

#define TEST3 1  // Test/timing for operators *= /=(const Array& rhs)

#define TEST4 1  // Test/timing for operators += -=(const T& rhs)

#define TEST5 1  // Test/timing for operators *= /=(const T& rhs)

#define TEST6 1  // Test/timing for operators * / (const T& rhs)
                 // Test/timing for XmultScalar

#define TEST7 1  // Test/timing for operators + - (const T& rhs)
                 // Test/timing for XplusScalar

#define TEST8 1  // Test/Timing for operators + - (const Array& rhs0, const Array& rhs1)
                 // Test/Timing for XplusY XminusY 

#define TEST9 1  // Test/Timing for operators * / (const Array& rhs0, const Array& rhs1)
                 // Test/Timing for XtimesY XdivY

#define TEST10 1 // Test/Timing for operators == != (const Array& rhs)

#define TEST11 1 // Test/Timing for Metric space category

#define TEST12 1 // Miscelaneous tests

  // --------------------------------------------------------

#if TEST12 || TEST_ALL
  {
  ConcreteFormedArray1d<double> fa10(10), fa20(20);

  fa10 = 10.0;
  fa20 = 20.0;

  cout << "\nfa10: " << fa10 << "\nfa20: " << fa20 << endl;

  fa10.swap( fa20 );

  cout << "\nfa10: " << fa10 << "\nfa20: " << fa20 << endl;

  FormedArithmetic1d<double> far30(30);

  far30 = 30.0;

  fa10.swap( far30 );

  cout << "\nfa10: " << fa10 << "\nfar30: " << far30 << endl;
  }
#endif

  // --------------------------------------------------------


#if TEST1 || TEST_ALL
  cout << "\n Test/timing for operator ++ -- - (negate) " << endl;

  {
    const int vec_dim = 250;
    const int n_oper = 200000;  

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim];
    double value = 10.0;

    for(int i=0; i<vec_dim; ++i)
      bia_a[i] = value;

    for(int iop=0; iop<n_oper; ++iop) {
      for(int i=0; i<vec_dim; ++i)
	bia_a[i]++;

      for(int i=0; i<vec_dim; ++i)
	++bia_a[i];

      for(int i=0; i<vec_dim; ++i)
	bia_a[i]--;     

      for(int i=0; i<vec_dim; ++i)
	--bia_a[i];
      
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
 
    FormedArithmetic1d<double> ra_a(vec_dim);

    ra_a = value;
    for(int iop=0; iop<n_oper; ++iop) {
      ra_a++;
      ++ra_a;
      ra_a--;
      --ra_a;
      -ra_a;
    }
   
    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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
    const int n_oper = 200000;  

Test/timing for operator ++ -- - (negate) 

 Time spent with built in arrays (s) = 2.93

 Time spent with FormedArithmetic1d arrays (s) = 21.96

  */
#endif

#if TEST2 || TEST_ALL
  cout << "\nTest/timing for operators += -=(const Array& rhs)" << endl;

  {
    const int vec_dim = 25000;
    const unsigned int n_equal = 2000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 10.0;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      /*
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = 0.0;
      }
      */
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_b[i] = 2*value;
      }
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

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      // cra_a.setToZero();
      cra_a = value;
      cra_b = 2*value;
      cra_a += cra_b;
      cra_a -= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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
    
    Time spent with built in arrays (s) = 2.37

    Time spent with FormedArithmetic1d arrays (s) = 3.61

  */
#endif

#if TEST3 || TEST_ALL
  cout << "\nTest/timing for operators *= /=(const Array& rhs)" << endl;

  {
    const int vec_dim = 25000;
    const unsigned int n_equal = 2000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim];
    double value = 10.0;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      /* for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = 1.0;
      }
      */
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_b[i] = 2*value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] *= bia_b[i];
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] /= bia_b[i];
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

    // --------------------------

    the_timer.set(1);
    the_timer.start(1);

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      // cra_a.setToOne();
      cra_a = value;
      cra_b = 2*value;
      cra_a *= cra_b;
      cra_a /= cra_b;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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
 
    Test/timing for operators *= /=(const Array& rhs)

    Time spent with built in arrays (s) = 5.79

    Time spent with FormedArithmetic1d arrays (s) = 6.77

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

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
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

    FormedArithmetic1d<double> cra_a(vec_dim);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;
      cra_a += value;
      cra_a -= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

    Time spent with built in arrays (s) = 1.84

    Time spent with FormedArithmetic1d arrays (s) = 2.91

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

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
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

    FormedArithmetic1d<double> cra_a(vec_dim);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;
      cra_a *= value;
      cra_a /= value;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

 Time spent with built in arrays (s) = 5.29

 Time spent with FormedArithmetic1d arrays (s) = 5.92

  */
#endif

#if TEST6 || TEST_ALL
  cout << "\nTest/timing for operators * / (const T& rhs)";
  cout << "\nTest/timing for XmultScalar" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;
    
    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim], bia_c[vec_dim];
    double value = 10.0;
    double recp_value = 1.0/value;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_b[i] = bia_a[i] * value;
      }
      for(int i=0; i<vec_dim; ++i) {
	// bia_c[i] = bia_a[i] / value;
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

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;

      cra_b = cra_a * value;
      //cra_b = value * cra_a;  // same as cra_a * value

      // cra_c = cra_a / value;    
      // or do: 
      cra_c = cra_a * (recp_value);

      //cra_c = value / cra_a;  // slower then cra_a / value
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;

      XmultScalar(cra_b, cra_a, value); // b = a * value

      XmultScalar(cra_c, cra_a, (recp_value) ); // c = a / value
    }

    the_timer.stop(2);
    cout << "\n Time spent with FormedArithmetic1d arrays (s)\n"
	 << " XmultScalar = "
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

 Time spent with built in arrays (s) = 1.4

 Time spent with FormedArithmetic1d arrays (s) = 7.65

 Time spent with FormedArithmetic1d arrays (s)
 XmultScalar = 2.77

  */
#endif

#if TEST7 || TEST_ALL
  cout << "\nTest/timing for operators + - (const T& rhs)";
  cout << "\nTest/timing for XplusScalar" << endl;

  {
    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

    the_timer.set(0);
    the_timer.start(0);

    double bia_a[vec_dim], bia_b[vec_dim], bia_c[vec_dim];
    double value = 10.0;

    for(unsigned  int equal=0; equal<n_equal; ++equal) {
      for(int i=0; i<vec_dim; ++i) {
	bia_a[i] = value;
      }
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

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;

      //cra_b = cra_a + value;
      cra_b = value + cra_a;  // same as cra_a + value

      cra_c = cra_a - value; // or cra_c =  cra_a + (-value);
      //cra_c = value - cra_a; // will call negate()
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      cra_a = value;

      XplusScalar(cra_b, cra_a, value); // b = a + value

      XplusScalar(cra_c, cra_a, (-value) ); // c = a - value

      // XplusScalar(cra_c, -cra_a, value ); // c = value - a; will call negate()
    }

    the_timer.stop(2);
    cout << "\n Time spent with FormedArithmetic1d arrays (s)\n"
	 << " XplusScalar = "
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

 Time spent with built in arrays (s) = 1.61

 Time spent with FormedArithmetic1d arrays (s) = 7.68

 Time spent with FormedArithmetic1d arrays (s)
 XplusScalar = 3.21

  */
#endif

#if TEST8 || TEST_ALL
  cout << "\nTest/Timing for operators + - (const Array& rhs0, const Array& rhs1)";
  cout << "\nTest/Timing for XplusY XminusY" << endl;

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

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      cra_b = cra_a + cra_a;

      cra_c = cra_a - cra_a;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      XplusY( cra_b, cra_a, cra_a ); // b = a + a

      XminusY( cra_c, cra_a, cra_a ); // c = a - a
    }

    the_timer.stop(2);
    cout << "\n Time spent with FormedArithmetic1d arrays (s)\n"
	 << " XplusY XminusY = "
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

 Time spent with built in arrays (s) = 0.96

 Time spent with FormedArithmetic1d arrays (s) = 7.16

 Time spent with FormedArithmetic1d arrays (s)
 XplusY XminusY = 2.35


  */
#endif

#if TEST9 || TEST_ALL
  cout << "\nTest/Timing for operators * / (const Array& rhs0, const Array& rhs1)" << endl;
  cout << "\nTest/Timing for XtimesY XdivY" << endl;

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
	bia_b[i] = bia_a[i] * bia_a[i];
      }
      for(int i=0; i<vec_dim; ++i) {
	bia_c[i] = bia_a[i] / bia_a[i];
      }
    }
    the_timer.stop(0);
    cout << "\n Time spent with built in arrays (s) = "
	 << the_timer.read(0) << endl;
    for(int i=0; i<vec_dim; ++i) {
      if ( bia_b[i] != value * value ) {
	cout << "error: expected " << value * value << 
	  " found " << bia_b[i] << endl;
	return EXIT_FAILURE;
      }
      if (   bia_c[i] != 1.0 ) {
	cout << "error: expected " << 1.0 << 
	  " found " << bia_c[i] << endl;
	return EXIT_FAILURE;
      }
    }
    
    // ------------------------

    the_timer.set(1);
    the_timer.start(1);

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      cra_b = cra_a * cra_a;

      cra_c = cra_a / cra_a;
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
	 << the_timer.read(1) << endl;

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

    // ----------------------------

    the_timer.set(2);
    the_timer.start(2);

    cra_a = value;
    for(unsigned int equal=0; equal<n_equal; ++equal) {

      XtimesY( cra_b, cra_a, cra_a ); // b = a * a

      XdivY( cra_c, cra_a, cra_a ); // c = a / a
    }

    the_timer.stop(2);
    cout << "\n Time spent with FormedArithmetic1d arrays (s)\n"
	 << " XtimesY XdivY = "
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

Test/Timing for operators * / (const Array& rhs0, const Array& rhs1)

    const int vec_dim = 250;
    const unsigned int n_equal = 200000;

 Time spent with built in arrays (s) = 4.65

 Time spent with FormedArithmetic1d arrays (s) = 10.1

 Time spent with FormedArithmetic1d arrays (s)
 XtimesY XdivY = 5.41

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

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim), cra_c(vec_dim);

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
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

 Time spent with FormedArithmetic1d arrays (s) = 3.25
a_eq_b = 1
a_eq_c = 0

  */
#endif

#if TEST11 || TEST_ALL
  cout << "\nTest/Timing for dot(const Array& rhs)" << endl;
  {
    const int vec_dim = 25000;
    const unsigned int n_equal = 3000;

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

    FormedArithmetic1d<double> cra_a(vec_dim), cra_b(vec_dim);

    cra_a = value;
    cra_b = value;
    cra_b(0) = 3.0;

    for(unsigned int equal=0; equal<n_equal; ++equal) {
      inner = cra_a.dot(cra_b);

      inner_a = cra_a.dot(cra_a);
      inner_b = cra_b.dot(cra_b);

      //inner_a = dot(cra_a, cra_a);
      //inner_b = dot(cra_b, cra_b);
 
    }

    the_timer.stop(1);
    cout << "\n Time spent with FormedArithmetic1d arrays (s) = "
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

 Time spent with built in arrays (s) = 3.26
inner_a_b = 2.78999999999998
inner_a = 2.49999999999999
inner_b = 11.4899999999999
norm_a = 1.58113883008419
norm_b = 3.38969025133565
cos_a_b = 0.520564064424075
Angle_a_b = 1.02328487483649

 Time spent with FormedArithmetic1d arrays (s) = 3.05000000000000
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


  return EXIT_SUCCESS;
}
// ***************************************************
// ***************************************************


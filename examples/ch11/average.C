/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/Array1d.h"
#include "Array/Array2d.h"
#include "Array/Array3d.h"
#include "Array/FormedArray2d.h"

#include <iostream>
//#include <strstream>
#include <sstream>
#include <float.h>

// CAD We moved lots of stuff to the include file below so
// we can use to it instantiate template explicitly

#include "average.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

double average(const Array2d<float>& a) {
    double sum = 0;
    cerr << "explicit average called instead of template" << endl;
    for (Subscript i = a.shape(0) - 1; i >= 0; i--) {
        for (Subscript j = a.shape(1) - 1; j >= 0; j--) sum += a(i, j);
    }
    return sum / a.numElts();
}

int main() {


  FormedArray2d<double> a(2,3); // FormedArray2d<T> is in Array2d<T>
                                // category
                                // EltT set to double.

  // ... set elements of a ...
  istrstream in("[[1 2 3] [4 5 6]]");
  in >> a;

  double avg = average(a);      // average() returns double
  cout << "average = " << avg << endl;

  if (avg != 21.0 / 6.0) { 
    cerr << "Bad average (" << avg << ")" << endl; return 1; 
  }

  // Demonstrate danger of global function template: template gets
  // expanded in preference to reference conversion.  Should not print
  // "explicit average" message above.
  
  FormedArray2d<float> b(10, 20);
  // ... set elements of b ...
  b = 1.75;
  average(b);

  cout << "average = " << average(b) << endl;  

  return 0;

}

// Force compilation of template so it gets checked
int sum(const Array2dWithTypedef<int>&) { return 0; }

void f(const Array2dWithTypedef<int>& a) {
  average(a);
}



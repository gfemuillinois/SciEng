/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/FormedArray.h"
#include "Array/RigidArray.h"
#include <iostream.h>


extern double sumsq(const Array1d<float>& a);


extern double sumsq(const Array1d<float>& a);
extern double sumsq(const FormedArray1d<float>& a);

double sumsq(const FormedArray1d<float>& a) { const Array1d<float>& t = a; return sumsq(t); }

double sumsq(const Array1d<float>& a) {
    double sum = 0.0;
    for (int i = a.shape(0)-1; i >= 0; i--) sum += a(i)*a(i);
    return sum;
}

int main() {

  // Read a size from stdin, create a 1-d array of that size,
  // read the array element values, and compute the sum of squares.
  int n;
  cin >> n;
  FormedArray1d<float> fa(n);
  cin >> fa;
  cout << "Sum of the squares of " << fa << " is " << sumsq(fa) << endl;

  // Read a 5-element array from stdin and compute its sum of squares
  RigidArray1d<float, 5> ra;
  cin >> ra;
  cout << "Sum of the squares of " << ra << " is " << sumsq(ra) << endl;

  return 0;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <complex>
#include <iostream>

using std::complex;

extern float zero;        // Forward declaration

complex<double> one(zero+1);      // Has value 1.0+0.0i
complex<double> two(zero+2);      // Has value 2.0+0.0i
float zero;               // Has value 0 by default.



int main() {
  cout << one << endl << two << endl;
  return 0;
}

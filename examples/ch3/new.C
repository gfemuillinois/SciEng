/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

  float* fp = new float;  // Allocate a float on the heap.
  // ...
  delete fp; // Deallocate.


  int n;
  cin >> n; // Read count
  float* x = new float[n];
  // ...
  delete [] x;

  return 0;
}

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

template<class T> T abs(T x) {
  if (x < 0) return -x;
  return x;
}

int main() {

extern double abs(double);
int i = -10;
float f = 100;
cout << abs(i) << " " << abs(f) << endl;

  return 0;
}

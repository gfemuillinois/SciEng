/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch6/SimpleArray.h"

void test() {

  const SimpleArray<int> a(5);

  int n = a.numElts(); // ok
#ifdef COMPILE_TEST
  // should issue: Assignment to constant expression is not allowed 
  a[0] = 1;            // Compile error!


#endif
}


const int x = 3;

#ifdef COMPILE_TEST
int& xr = x; // WRONG: const int cannot be converted to int&


#endif


int y = 4;
const int& yr = y; // OK


void test2() {

SimpleArray<int> a(5);
SimpleArray<int> b(5);
#ifdef COMPILE_TEST
// Should issue private member ... cannot be accessed 
a.copy(b);  // Compile Error!

#endif
}

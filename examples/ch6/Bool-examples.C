/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/Boolean.h"
#include "SciEng/utils.h"


Boolean has_real_solution(double a, double b, double c) {
    // Does ax**2 + bx + c = 0 have a real solution?
    return sce::sqr(b) >= 4 * a * c;
}


int main() {

  Boolean b1(Boolean::IsTrue); // Calls Boolean(int)
  Boolean b2(3);             // Calls Boolean(int)
  int* p_i = new int(3);
  Boolean b3(p_i);           // Calls Boolean(void*)
  Boolean b4(3.0);           // Calls Boolean(float)


  delete p_i;
  int a = 1;
  int b = 0; 
  int c = 3;

  if ( has_real_solution(a, b, c) ) {
    // ...
    return 1;
  }

  Boolean b5(Boolean::IsFalse);
  return (!b5)?0:1;
}

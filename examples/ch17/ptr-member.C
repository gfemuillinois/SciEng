/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Algebra/ComplexFloat.h"

int main() {

  typedef ComplexFloat& (ComplexFloat::* CFOp)(const ComplexFloat&);
  CFOp op = ComplexFloat::operator+=;


  ComplexFloat a(1, 2);
  ComplexFloat b(3, 4);
  cout << (a.*op)(b) << endl;


  op = ComplexFloat::operator-=;
  cout << (a.*op)(b) << endl;


  ComplexFloat* p = &a;
  cout << (p->*op)(b) << endl;

  return 0;
}

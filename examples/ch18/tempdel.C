/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/SciEngString.h"

void f(const char*) { }

int main() {

  extern void f(const char*);

  String s1 = "abc";
  String s2 = "def";
  f( (s1 + s2).c_str() );


  String temp(s1 + s2);
  f(temp.c_str());

  return 0;
}

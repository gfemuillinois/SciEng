/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/String.h"
#include <stdlib.h>
#include <iostream>

template<class Array>
void check(const Array& a, const char* comp_string) {
  String s;
  s << a;
  if (s != String(comp_string)) {
    cerr << "\nArray check failed:\n\tGot:\t\t" << s << "\n\tExpected:\t" << comp_string << endl;
    exit(1);
  }
}

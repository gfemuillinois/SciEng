/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/FormedArray1d.h"
#include "SciEng/EquivalentCategory.h"
                                

#include "tEquality.h"


int main() {

  ComparableFormedArray1d<int> a(4);
  ComparableFormedArray1d<int> b(4);
  // Set elements of a and b...
  a = 3; b = 2;

  if ( a == b ) {
    // ...
  }
  // ...
  if ( a != b ) {
    // ...
  }

  if (!(a == b) && (a != b)) 
    return 0;

  return 1;
}

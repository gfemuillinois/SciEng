/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <strstream.h>
#include <stdlib.h>
#include "examples/ch4/CheckedSimpleArray.h"

int main() {

  try { 
    CheckedSimpleArray<float> a1(-3); // Bad size
    return EXIT_FAILURE;  // Shouldn't get here
  }
  catch(ArraySizeError e) {
    cerr << "ArraySizeError caught, bad size = " << e.badSize() << endl;
  }
  try {
    CheckedSimpleArray<float> a(3);
    a[3];// Bad subscript
    return EXIT_FAILURE;  // Shouldn't get here
  }
  catch(SubscriptRangeError e) {
    cerr << "SubscriptRangeError caught bad subscript = " << e.badSubscript() << endl;
  }


{
  istrstream cin("10 2");

  try {
    int n;
    cin >> n;
    CheckedSimpleArray<float> a(n);

    // ...

    int j;
    cin >> j;
    float x = 2.1 * a[j];

    // ...
}
  catch(SubscriptRangeError e) {
    cerr << "SubscriptRangeError caught bad subscript = " << e.badSubscript() << endl;
  }
  catch(ArraySizeError e) {
    cerr << "ArraySizeError caught, bad size = " << e.badSize() << endl;
  }

}
  return 0;  
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "examples/ch10/CheckedFloatArray.h"


float average(SimpleFloatArray& a) {
    double sum = 0.0;
    for (int i = 0; i < a.numElts(); i++) sum += a[i];
    return sum / a.numElts();
}

void f() {
  CheckedFloatArray a(10);
  // ... set values in a
  cout << average(a) << endl;

}

int main() {
  // Check operation as array

  CheckedFloatArray a(10);

  for (int i = 0; i < a.numElts(); i++) a[i] = 2*i;
  CheckedFloatArray b(a);
  if (a.numElts() != b.numElts()) { cerr << "Bad copy: numElts wrong" << endl; return 1; }
  for (i = 0; i < b.numElts(); i++) {
    if (b[i] != 2*i) { cerr << "Bad copy: elements wrong" << endl; return 1; }
  }
  b = 10;
  for (i = 0; i < b.numElts(); i++) {
    if (b[i] != 10) { cerr << "Bad assignment of scalar" << endl; return 1; }
  }
  b = a;
  for (i = 0; i < b.numElts(); i++) {
    if (b[i] != 2*i) { cerr << "Bad array assignment" << endl; return 1; }
  }
  
  if (average(a) != 9) { cerr << "Bad average: " << average(a) << endl; return 1; }

  // Check that errors are caught
  try {
   b[100];
   cerr << "Bad subscript not caught" << endl;
   return 1;
  } catch(CheckedFloatArray::SubscriptRangeError) {
  }

  return 0;
}

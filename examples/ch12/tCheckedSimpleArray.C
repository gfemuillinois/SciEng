/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "examples/ch11/CheckedSimpleArray.h"

#include "tCheckedSimpleArray.h"

void f() {
  CheckedSimpleArray<float> a(10);
  // ... set values in a
  cout << average(a) << endl;

}

int main() {

  // Check operation as array
  CheckedSimpleArray<float> a(10);
  for (int i = 0; i < a.numElts(); i++) a[i] = 2*i;

  CheckedSimpleArray<float> b(a);
  if (a.numElts() != b.numElts()) { cerr << "Bad copy: numElts wrong" << endl; return 1; }

  for (int i = 0; i < b.numElts(); i++) {
    if (b[i] != 2*i) { cerr << "Bad copy: elements wrong" << endl; return 1; }
  }
  b = 10;
  for (int i = 0; i < b.numElts(); i++) {
    if (b[i] != 10) { cerr << "Bad assignment of scalar" << endl; return 1; }
  }
  b = a;
  for (int i = 0; i < b.numElts(); i++) {
    if (b[i] != 2*i) { cerr << "Bad array assignment" << endl; return 1; }
  }
  
  if (average(a) != 9) { cerr << "Bad average: " << average(a) << endl; return 1; }

  // Check that errors are caught
  try {

   b[100];
   cerr << "Bad subscript not caught" << endl;
   return 1;
  } catch(CheckedSimpleArray<float>::SubscriptRangeError) {

  }

 {

   CheckedSimpleArray<int> ia(4);                           // ok
   CheckedSimpleArray<int*> ipa(4);                         // ok

   typedef float Coord;
   CheckedSimpleArray<Coord> ca(4);                         // ok
   CheckedSimpleArray<float> fa(4);                         // ok, same as previous.

   CheckedSimpleArray< CheckedSimpleArray<int> > iaa(4);    // ok

   
 }
  return 0;
}

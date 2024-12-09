/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/


#include "tASGArray.h"

using std::cout;
using std::cin;
using std::endl;

AdditiveArray& AdditiveArray::operator+=(const AdditiveArray& rhs) {
    if (numElts() != rhs.numElts()) throw "Mismatched sizes";
    IteratorType i(*this);
    for (BrowserType j(rhs); j.more(); i.advance(), j.advance()) i.current() += j.current();
    return *this;
}


int main() {

  AdditiveArray a(3);
  a(0) = 2; a(1) = 3; a(2) = 4;
  AdditiveArray b(3);
  b(0) = 5; b(1) = 6; b(2) = 7;
  cout << a + b << endl; // Prints: [7, 9, 11]

  return 0;
}

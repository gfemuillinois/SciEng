/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "Algebra/AbelianSemiGroupCategory.h"
#include "Array/ConcreteFormedArray1d.h"


class AdditiveArray :
    public ConcreteFormedArray1d<double>,
    public AbelianSemiGroupCategory<AdditiveArray> {
public:
    AdditiveArray(Subscript n) : ConcreteFormedArray1d<double>(n) {}
    AdditiveArray(const AdditiveArray& a) : ConcreteFormedArray1d<double>(a) {}
    // ... other constructors and assignment operators

    // User must define for Abelian semigroup category
    AdditiveArray& operator+=(const AdditiveArray& rhs);
};



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

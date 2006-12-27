//
// Test for class SciEngLib::Boolean
//

#include <iostream>
#include "SciEng/Boolean.h"

int main() {

  //  using SciEngLib::Boolean;

  Boolean b1, b2(0), b3(3.5);

  b1 = Boolean::IsTrue;

  std::cout << "b1 = " << b1 << "\t b2 = " << b2 << "\t b3 = " << b3 << std::endl;

}

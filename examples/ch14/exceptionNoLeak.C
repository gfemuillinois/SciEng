/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ConcreteFormedArray1d.h"
#include "SciEng/CopiedObjPtr.h"


class NonLeaker {
public:
    NonLeaker(Subscript size) : p(new double(0)), array(size) {}
private:
    CopiedBuiltInPtr<double> p;
    ConcreteFormedArray1d<int> array;
};

void f() {
    // ...
    NonLeaker l(-3);
}


int main() {
  try { f(); } catch(...) {}
  return 0;
}

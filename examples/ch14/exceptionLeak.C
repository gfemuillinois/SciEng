/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ConcreteFormedArray1d.h"


class Leaker {
public:
    Leaker(Subscript size) : p(new double(0)), array(size) {}
    Leaker(const Leaker& lkr) : p(new double(*lkr.p)) {}
    Leaker& operator=(const Leaker& lkr) { 
        p = new double(*lkr.p);
        array = lkr.array;
        return *this;
    }
    ~Leaker() { delete p; }
private:
    double* p;
    ConcreteFormedArray1d<int> array;
};

void f() {
    // ...
    Leaker l(-3);
}


int main() {
  try { f(); } catch(...) {}
  return 0;
}

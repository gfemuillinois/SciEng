/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "examples/ch6/SimpleArray.h"
#include "examples/ch11/tuplize.h"
using std::cout;
using std::cin;
using std::endl;

int main() {

SimpleArray<int> ia(4);
ia = 3;
tuplize(cout, ia);
cout << endl;
SimpleArray<double> da(4);
da = 5.1;
tuplize(cout, da);
cout << endl;

return 0;
}

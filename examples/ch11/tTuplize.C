/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "examples/ch6/SimpleArray.h"
#include "examples/ch11/tuplize.h"

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

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "Algebra/SemiGroupCategory.h"

#include "tIntMod5.h"

int main() {    
    IntMod5 a = 2;
    IntMod5 b = 4;
    cout << a * b << " " << a.pow(4) << " " << a << " " << pow(b, 3) << endl;
    return 0;
};


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void f() {

    float x;
    cin >> x;             // Read value of x
    const float xc = x;
    // ...

}


int main() {

const float h = 6.6256e-34;   // Planck's constant (mks units)

f();
return 0;
}



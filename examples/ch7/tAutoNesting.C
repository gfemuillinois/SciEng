/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "examples/ch7/TraceLifetime.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "-- main starts --" << endl;
    TraceLifetime a1("a1");
    for (int i = 1; i <= 2; i++) {
        cout << " -- loop i= " << i << " -- " << endl;
        TraceLifetime a2("a2"); // Object created each loop iteration.
        if (i == 2) {
            TraceLifetime a3("a3"); // Object created iff i == 2.
        }
    }
    cout << "-- loop is done -- " << endl;
    TraceLifetime a4("a4");
    cout << "-- main ends --" << endl;
    return 0;
}


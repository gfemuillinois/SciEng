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

static TraceLifetime s1("s1"); // File scope static object.
 
void fnc(int j) { 
    cout << "-- starting fnc(" << j << ") --" << endl;


    static TraceLifetime s2("s2");      // Local scope: created on first call to fnc().
    if (j == 2) {
        static TraceLifetime s4("s4");  // Only created when j == 2.
    }
    for (int i = 1; i <= 2; i++) {
        cout << "-- loop i=" << i << " --" << endl;
        static TraceLifetime s3("s3");  // Local scope: created once, when i == 1.
    }


    cout << "-- returning from fnc(" << j << ") --" << endl;
}
 
int main() { 
    cout << "-- main starts --" << endl;
    fnc(1);
    fnc(2);
    cout << "-- main ends --" << endl;
    return 0;
}
 
static TraceLifetime s5("s5"); // File scope static object.


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

void f2() {
    cout << "-- f2 starts -- " << endl;
    TraceLifetime c("c");
    throw "exception";
    cout << "-- f2 ends -- " << endl;
}

void f1() {
    cout << "-- f1 starts -- " << endl;
    TraceLifetime a("a");
    f2();
    TraceLifetime b("b");
    cout << "-- f1 ends -- " << endl;
}

int main() {
    cout << "-- main starts --" << endl;
    try { 
        f1();
    }
    catch(const char*) {
        cout << "Exception caught." << endl;
    }
    cout << "-- main ends --" << endl;
    return 0;
}


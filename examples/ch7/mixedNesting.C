/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch7/TraceLifetime.h"

TraceLifetime s1("s1");
 
int main() {
    static TraceLifetime s2("s2");
    TraceLifetime a1("a1");
    TraceLifetime a2("a2");
    for (int i = 1; i <= 2; i++) {
        TraceLifetime a3("a3");
        static TraceLifetime s3("s3");
    }
    TraceLifetime a4("a4");

    return 0;
}


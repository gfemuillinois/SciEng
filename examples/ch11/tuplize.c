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


template<class T>
std::ostream& tuplize(std::ostream& os, const SimpleArray<T>& a) {
    // Output a comma-separated list of T's
    int n = a.numElts();
    for (int i = 0; i < n; i++) {
        os << a[i];
        if (i < n-1) os << ", ";
    }
    return os;
}


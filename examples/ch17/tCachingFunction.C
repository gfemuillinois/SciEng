/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "Function/CachingFunction.h"


float f(float x) {  // Expensive computation  
    cout << "f called" << endl;
    return 2 * x;
}

int main() { 
    CachingFunction<float, float> f_cache(f);
    cout << f_cache(1) << endl;
    cout << f_cache(1) << endl;
    cout << f_cache(2) << endl;
    cout << f_cache(2) << endl;
    cout << f_cache(3) << endl;
    return 0;
}


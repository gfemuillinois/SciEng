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

void dangle(int j) {  // WARNING:  Incorrect code
    int* p;
    if (j < 100) {
        // Dangling reference created when this block terminates
        int iarray[100];
        p = iarray;
    }
    else p = new int[j];
    for (int i = 0; i < j; i++) p[i] = i;
}



void f(int* x) {
    // ...
    delete [] x;      // Causes dangling reference
}

void dynamic_dangle(int size) {  // WARNING: Incorrect code
    int* iarray = new int [size];
    f(iarray);
    for (int i = 0; i < size; i++) cout << iarray[i];
}


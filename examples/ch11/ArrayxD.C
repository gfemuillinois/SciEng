/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "ArrayxD.h"


double sum(const Array2d<double>& a) {
    double sum = 0.0;
    for (Subscript i = a.shape(0)-1; i >= 0; i--) {
        for (Subscript j = a.shape(1)-1; j >= 0; j--) sum += a(i, j);
    }
    return sum;
}


#include "examples/ch11/sum.h"

void f(const Array2d<int>& a) {
  int x = sum(a);
}


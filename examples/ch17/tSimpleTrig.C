/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <stdlib.h>
#include <math.h>

class SimpleTrig { 
public:
    SimpleTrig(double (*f)(double)) : the_function(f) {}
    double operator()(double v) { return the_function(v); }
private:
    double (*the_function)(double);
};

main(){


SimpleTrig aTrigF(sin);     // Capture double sin(double);
double d1 = sin(2.3);       // Call sin function.
double d2 = aTrigF(2.3);    // Call operator, which then calls sin function.


if (d1 == d2) return EXIT_SUCCESS;
return EXIT_FAILURE;
}


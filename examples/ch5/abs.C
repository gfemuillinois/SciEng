/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// Include standard headers to ensure consistency with
// our declarations of abs, etc.
#include <math.h>
#include <complex.h>



extern int    abs(int);
extern double abs(double);
extern double abs(complex);



void foo() {


extern int    abs(int&);
extern double abs(double&);
extern double abs(complex&);


}

int main() {

int i = -3;

int iabs    = abs(i);  // Calls abs(int)
double d = 3.2; 
double dabs = abs(d);  // Calls abs(double)
complex c(-1, 2);
double cabs = abs(c);  // Calls abs(complex)


return 0;
}

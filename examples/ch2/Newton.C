/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <math.h>
static double f(double x) { return x*x-2; }
static double fprime(double x) { return 2*x; }
int main() {
double x, dx;
const double initial_guess = 10;
const double desired_accuracy = 1e-5;

x = initial_guess;
do {

    dx = f(x) / fprime(x);
    x  -= dx;

} while (fabs(dx) > desired_accuracy);

cout << x << endl;
return 0;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

#include <cmath>
#include <cstdlib>


extern double my_random();// Returns uniform deviates in (0, 1)

static double exp_random(double mu) {
    // Generates exponentially distributed random deviates using
    // the transformation method described in Knuth, 2nd ed.,
    // Seminumerical Algorithms, Section 3.4.D, Addison-Wesley, 1981.
    return -mu * log(my_random());
}

void simulation1() {
    // ...
    double x1 = exp_random(2.1);
    // ...
}

void simulation2() {
    // ...
    double x2 = exp_random(3.5);
    // ...
}


double my_random() {
  // Warning:  this uses drand48, which is a crummy random number generator.
  return drand48();
}

int main() {
  simulation1();
  simulation2();
  return 0;
}  

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>

double coulombsLaw(double q1, double q2, double r) {
    // Coulomb's law for the force acting on two point charges
    // q1 and q2 at a distance r.  MKS units are used.

    const double k = 8.9875e9;     // nt-m**2/coul**2
    return k * q1 * q2 / (r * r);

}

int main() {
    cout << coulombsLaw(1.6e-19, 1.6e-19, 5.3e-11) << " newtons" << endl;
    return 0;
}


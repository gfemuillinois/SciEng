
#include "examples/ch2/coulombsLaw.h"

double coulombsLaw(double q1, double q2, double r) {
    // Coulomb's law for the force acting on two point charges
    // q1 and q2 at a distance r.  MKS units are used.

    const double k = 8.9875e9;     // nt-m**2/coul**2
    return k * q1 * q2 / (r * r);

}

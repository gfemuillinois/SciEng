
#ifndef ATWOODSMACHINEH
#define ATWOODSMACHINEH

#include <iostream>
#include "Units/SIConstants.h"
#include "Units/BritishConstants.h"

class AtwoodsMachine :
    private SIConstants<double> {
public:
    AtwoodsMachine(Mass m1, Mass m2) : the_m1(m1), the_m2(m2) {}
    Acceleration m1Accel() const {
        return g * (the_m2 - the_m1) / (the_m2 + the_m1);
    }
    Force tension() const {
        return g * (2 * the_m1 * the_m2) / (the_m1 + the_m2);
    }
private:
    Mass the_m1;
    Mass the_m2;
};



class DemoAtwoodsMachine :
    private BritishConstants<double> {
public:
    static void demo();
};

#endif

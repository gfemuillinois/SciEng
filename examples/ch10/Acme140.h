/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Acme130_VS_GI_GC.h"


class Acme140 : 
    public Acme130_VS_GI_GC {
public:
    enum Jumper { J1, J2 }; // Possible jumper settings

    Acme140(GPIBController& controller, int gpib_address, Jumper j);
    virtual float maximum() const;
private:
    float max_voltage;
};


inline

Acme140::Acme140(GPIBController& controller, int gpib_address, Jumper j) : 
    Acme130_VS_GI_GC(controller, gpib_address),
    max_voltage(j == J1 ? 10.0 : 50.0) {
}


inline

float Acme140::maximum() const { 
    return max_voltage;
}


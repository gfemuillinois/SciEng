/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/VoltageSupply.h"
#include "examples/ch9/GPIBController_Stub.h"
                   
                   


class Acme130_VS :
    public VoltageSupply {
public:         
    Acme130_VS(GPIBController_Stub& controller, int gpib_address);

    virtual void  set(float volts);
    virtual float minimum()        const;
    virtual float maximum()        const;

private:        
    GPIBController_Stub my_controller;
    int my_gpib_address;
};


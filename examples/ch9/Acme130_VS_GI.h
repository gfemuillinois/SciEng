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
#include "examples/ch9/GPIBInstrument.h"
   

class Acme130_VS_GI :            
    public VoltageSupply,
    public GPIBInstrument {
public:         
    Acme130_VS_GI(GPIBController_Stub& controller, int gpib_address);

// VoltageSupply interface

    virtual void set(float volts);
    virtual float minimum() const;
    virtual float maximum() const;

// GPIBInstrument interface

    virtual void  send(const char*); // Command.
    virtual void  send(float f);     // Command with value.
    virtual float receive();         // Data point.


private:        
    GPIBController_Stub my_controller;
    int my_gpib_address;
};




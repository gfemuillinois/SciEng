/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/VoltageSupply.h"
#include "examples/ch9/GPIBController.h"
#include "examples/ch9/GPIBInstrument.h"
   

class Acme130_VS_GI_GC :            
    public VoltageSupply,
    public GPIBInstrument {
public:         
    Acme130_VS_GI_GC(GPIBController& controller, int gpib_address);

    // ... member functions, as in Acme130_VS_GI ...

// VoltageSupply interface
    virtual void set(float volts);
    virtual float minimum() const;
    virtual float maximum() const;

// GPIBInstrument interface
    virtual void send(const char*);
    virtual void send(float f);
    virtual float receive();

private:        
    GPIBController& my_controller;
    int my_gpib_address;
};




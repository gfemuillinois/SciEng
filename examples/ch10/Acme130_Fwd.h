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
#include "examples/ch10/GPIBInstrumentData.h"
   

class Acme130_Fwd :          
    public VoltageSupply,
    public GPIBInstrument {
public:         
    Acme130_Fwd(GPIBController& controller, int gpib_address) :
        gpib_rep(controller, gpib_address, "Acme130_Fwd") {}

// VoltageSupply interface
    virtual void set(float volts);
    virtual float minimum() const;
    virtual float maximum() const;

// GPIBInstrument interface

    virtual void  send(const char* cmd) { gpib_rep.send(cmd);        }
    virtual void  send(float f)         { gpib_rep.send(f);          }
    virtual float receive()             { return gpib_rep.receive(); }


private:        
    GPIBInstrumentData gpib_rep;
};




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
#include "examples/ch10/GPIBInstrumentData_GI.h"
   

class Acme130_GIData :
    public virtual VoltageSupply,
    public virtual GPIBInstrument,
    private GPIBInstrumentData_GI {
public:         
    Acme130_GIData(GPIBController& controller, int gpib_address);

// VoltageSupply interface
    virtual void set(float volts);
    virtual float minimum() const;
    virtual float maximum() const;
};




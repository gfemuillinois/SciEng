/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Acme230H
#define Acme230H
#include "examples/ch10/Acme130_GIData.h"


class Acme230 :
    public virtual VoltageSupply,
    public virtual GPIBInstrument,
    private Acme130_GIData {
public:
    Acme230(GPIBController& which_GPIB, int what_address);

    virtual void set(float volts); 
    virtual float  maximum() const; 

    enum Range { high, low };
    virtual void set(Range r);
private:
    Range range_setting;
};


#endif

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
#include "examples/ch10/Acme130_Acs.h"


class Acme230 :
    public virtual VoltageSupply,
    public virtual GPIBInstrument,
    private Acme130_Acs {
public:
    Acme230(GPIBController& which_GPIB, int what_address);


    Acme130_Acs::minimum;     // Expose portion of Acme130_Acs VoltageSupply interface

    Acme130_Acs::send;        // Expose portion of Acme130_Acs GPIBInstrument interface
    Acme130_Acs::receive;


    virtual void   set(float volts) { Acme130_Acs::set(volts); } // Unhide.
    virtual double maximum()        const;                       // Override.


    enum Range { high, low }; // Range adjustments

    void set(Range r);
private:
    Range range_setting;
};


#endif

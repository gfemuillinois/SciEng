/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/GPIBInstrument.h"
#include "examples/ch9/GPIBController.h"


class GPIBInstrumentData_GI:         
    public virtual GPIBInstrument {
public:
    GPIBInstrumentData_GI(GPIBController& c, int address, const char* name);

// GPIBInstrument interface

    virtual void  send(const char*);    // Command.
    virtual void  send(float f);        // Command with value.
    virtual float receive();            // Data point.

private:
    GPIBController& my_controller;
    int my_gpib_address;
};


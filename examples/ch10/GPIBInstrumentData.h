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


class GPIBInstrumentData {
public:
    GPIBInstrumentData(GPIBController& c, int address, const char* name);

// GPIBInstrument interface

    void  send(const char*);    // Command.
    void  send(float f);        // Command with value.
    float receive();            // Data point.

private:
    GPIBController& my_controller;
    int my_gpib_address;
};


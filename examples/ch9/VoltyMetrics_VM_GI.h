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
#include "examples/ch9/Voltmeter.h"

// Not Shown
class VoltyMetrics_VM_GI :  
    public Voltmeter,
    public GPIBInstrument {
public:
    VoltyMetrics_VM_GI(GPIBController& controller, int what_address);

// Voltmeter interface

    virtual float read();

// GPIBInstrument interface

    virtual void  send(const char*); // Command.
    virtual void  send(float f);     // Command with value.
    virtual float receive();         // Data point.


private:
    GPIBController& my_controller;
    int my_gpib_address;
};


      

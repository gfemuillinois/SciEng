/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/VoltageSupply.h"
#include "examples/ch9/GPIBInstrument.h"


class Acme130_NoV :       
    public VoltageSupply,
    public GPIBInstrument {
    // members here...
};

class Acme230_NoV : 
    public Acme130_NoV {
    // members here...
};



class VoltOn59_NoV :       
    public VoltageSupply,
    public GPIBInstrument {
    // members here...
};

class VoltOn59Dual_NoV : 
    public VoltOn59_NoV {
    // members here...
};


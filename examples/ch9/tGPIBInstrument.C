/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include "examples/ch9/GPIBController_GC.h"
#include "examples/ch9/GPIBInstrument.h"
#include "examples/ch9/Acme130_VS_GI_GC.h"
#include "examples/ch9/VoltyMetrics_VM_GI.h"


void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to) { 
    to.send( from.receive() );
}


int main() {
  GPIBController_GC gpib;
  Acme130_VS_GI_GC supply(gpib, 12);
  VoltyMetrics_VM_GI meter(gpib, 13);
  transferOnGPIB(meter, supply);
  return 0;
}

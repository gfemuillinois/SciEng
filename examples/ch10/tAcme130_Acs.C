/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/Acme130_Acs.h"
#include "examples/ch9/GPIBController_GC.h"


int main() {
  GPIBController_GC gpib;

  Acme130_Acs supply(gpib, 12);
  supply.send(15);

  return 0;
}

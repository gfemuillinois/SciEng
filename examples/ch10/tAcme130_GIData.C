/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/Acme130_GIData.h"
#include "examples/ch9/GPIBController_GC.h"

int main() {

  GPIBController_GC gpib;

  GPIBInstrument* s1p = new Acme130_GIData(gpib, 12);
  s1p->send(15);
  GPIBInstrument& supply1 = *s1p;
  supply1.send(15);

  {
#ifdef COMPILE_CHECK

  Acme130_GIData supply1(gpib, 12);
  supply1.send(15); // WRONG: can't access private member

#endif
  }
  delete s1p;
  return 0;
}

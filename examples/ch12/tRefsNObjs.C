/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/Acme130_VS.h"
#include "examples/ch9/VoltOn59_VS.h"

int main() {
GPIBController_Stub gpib;

   Acme130_VS a(gpib, 12);
   VoltageSupply& ar = a;
   VoltOn59_VS v(gpib, 13);
   VoltageSupply& vr = v;

   return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch9/GPIBController_GC.h"
#include "examples/ch9/Acme130_VS_GI_GC.h"
#include "examples/ch9/VoltyMetrics_VM_GI.h"
#include "examples/ch9/IVTester.h"

int main() {

  GPIBController_GC gpib;

  Acme130_VS_GI_GC supply(gpib, 12);
  VoltyMetrics_VM_GI meter(gpib, 13);
  IVTester iv(supply, meter);
  double v_step = 1.0;
  for (int i = 0; i < 10; i++) { 
    cout << iv.current(v_step * i) << endl;
}

  return 0;
}

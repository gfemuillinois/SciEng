/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include "examples/ch10/Acme230.h"
#include "examples/ch9/GPIBController_GC.h"
#include "examples/ch9/VoltyMetrics_VM_GI.h"

#include "examples/ch10/checkCalibration_VS_VM.h"
 
int main() {
  {
  GPIBController_GC gpib;

  Acme230 supply_3(gpib, 15);
  supply_3.set(Acme230::high);

  }
  {
  GPIBController_GC gpib;

  Acme230 supply_3(gpib, 15);
  supply_3.set(Acme230::high);
  VoltyMetrics_VM_GI meter(gpib, 14);
  cout << "Acme230 relative error at 60 volts is: " << checkCalibration(supply_3, meter, 60.0) << endl;

  }
  return 0;
}

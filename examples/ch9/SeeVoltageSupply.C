/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <cmath>
#include <iostream>

#include "examples/ch9/Acme130_VS.h"
#include "examples/ch9/VoltOn59_VS.h"


#include "examples/ch9/VoltyMetrics.h"
#include "examples/ch9/checkCalibration_VS.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
GPIBController_Stub gpib;
{


VoltyMetrics meter(gpib, 14);
Acme130_VS   supply1(gpib, 12);
VoltOn59_VS  supply2(gpib, 13);

cout << "Acme130_VS relative error at 1 volt is: " << checkCalibration(supply1, meter, 1.0) << endl;
cout << "VoltOn59_VS relative error at 1 volt is: " << checkCalibration(supply2, meter, 1.0) << endl;

}
{

Acme130_VS      supply1(gpib, 12);
VoltyMetrics meter(gpib, 14);
cout << "Acme130_VS relative error at 1 volt is: " << checkCalibration(supply1, meter, 1.0) << endl;

}
{

VoltOn59_VS     supply2(gpib, 13);
VoltyMetrics meter(gpib, 14);
cout << "VoltOn59_VS relative error at 1 volt is: " << checkCalibration(supply2, meter, 1.0) << endl;

}
  return 0;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch10/Acme140.h"
#include "examples/ch9/GPIBController_GC.h"


void display_max_voltage(Acme130_VS_GI_GC s) {
    cout << "Maximum output voltage is " << s.maximum() << endl;
}

int main() {

  GPIBController_GC gpib;

  Acme140 supply1(gpib, 12, Acme140::J2);
  Acme140 supply2(gpib, 13, Acme140::J1);
  Acme130_VS_GI_GC supply3(gpib, 14);



  // Use directly
  cout << supply1.maximum() << endl;      // Displays 50
  cout << supply2.maximum() << endl;      // Displays 10
  cout << supply3.maximum() << endl;      // Displays 10

  // Use as Acme130_VS_GI_GC
  Acme130_VS_GI_GC& s1_as_130 = supply1;
  Acme130_VS_GI_GC& s2_as_130 = supply2;
  Acme130_VS_GI_GC& s3_as_130 = supply3;
  cout << s1_as_130.maximum() << endl;    // Displays 50
  cout << s2_as_130.maximum() << endl;    // Displays 10
  cout << s3_as_130.maximum() << endl;    // Displays 10

  // Use as VoltageSupply
  VoltageSupply& v1 = supply1;
  VoltageSupply& v2 = supply2;
  VoltageSupply& v3 = supply3;
  cout << v1.maximum() << endl;           // Displays 50
  cout << v2.maximum() << endl;           // Displays 10
  cout << v3.maximum() << endl;           // Displays 10




  supply1.set(15);        // Works
try {
  supply2.set(15);        // Throws an exception
  return 1;
} catch (...) {}
  s1_as_130.set(15);      // Works
try {
  s2_as_130.set(15);      // Throws an exception
  return 1;
} catch (...) {}
  v1.set(15);             // Works
try {
  v2.set(15);             // Throws an exception


  return 1;
} catch (...) {}

  // Illustrate slicing


  display_max_voltage(supply1);   // Displays: Maximum output voltage is 10
  display_max_voltage(supply2);   // Displays: Maximum output voltage is 10


  return 0;
}

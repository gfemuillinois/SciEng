/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
extern void flushWithWater();
extern void coolingWaterOn();
extern void coolingWaterOff();
extern void heaterOn();
extern void heaterOff();

int f() {
float current_temp = 1;
float  maximum_safe_temp = 2;
float  operating_temp = 3;
float  temp_tolerance = 4;


if (current_temp > maximum_safe_temp) {
    cerr << "EMERGENCY: Too hot--flushing" << endl;
    flushWithWater();
}


if (current_temp > maximum_safe_temp)
    cerr << "EMERGENCY: Too hot--flushing" << endl;


// WRONG!
if (current_temp > maximum_safe_temp)
    cerr << "EMERGENCY: Too hot--flushing" << endl;
    flushWithWater();



if (current_temp > maximum_safe_temp) {
    // Emergency cool down.
    cerr << "EMERGENCY: Too hot--flushing" << endl;
    flushWithWater();
}
else {
    // Normal control strategy.
    if (current_temp > operating_temp + temp_tolerance) {
        heaterOff();
        if (current_temp > operating_temp + 2*temp_tolerance) {
            coolingWaterOn();
        }
    }

    if (current_temp < operating_temp - temp_tolerance) {
        coolingWaterOff();
        if (current_temp < operating_temp - 2*temp_tolerance) {
            heaterOn();
        }
    }
}

return 0;
}

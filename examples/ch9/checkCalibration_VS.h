/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

float checkCalibration(VoltageSupply& supply, VoltyMetrics& meter, float tst_voltage) {
    // Relative error at specified test voltage.
    supply.set(tst_voltage);
    return fabs(tst_voltage - meter.read()) /  tst_voltage;
}



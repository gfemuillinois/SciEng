/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include <iostream.h>

#include "examples/ch9/GPIBController_Stub.h"


class Acme130 {
public:         
    Acme130(GPIBController_Stub& controller, int gpib_address);
    void set(float volts);
    double minimum() const;
    double maximum() const;
private:        
    GPIBController_Stub my_controller;
    int my_gpib_address;
};



class VoltOn59 {
public:         
    VoltOn59(GPIBController_Stub& controller, int gpib_address);
    void set(float volts);
    double minimum() const;
    double maximum() const;
private:        
    GPIBController_Stub my_controller;
    int my_gpib_address;
};


// Common code in test/SeeCommonality.C and test/SeeVoltageSupply.C

#include <strstream.h>


void VoltOn59::set(float volts) {
  my_controller.send(my_gpib_address, volts);
}



void Acme130::set(float volts) { 
    if (volts > maximum() || volts < minimum()) throw "Acme 130 voltage out of range";
    my_controller.send(my_gpib_address, volts);
}


double VoltOn59::minimum() const { return 0.0; }
double VoltOn59::maximum() const { return 100.0; }
double Acme130::minimum() const { return 0.0; }
double Acme130::maximum() const { return 10.0; }




Acme130::Acme130(GPIBController_Stub& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("Acme130", gpib_address);
}



VoltOn59::VoltOn59(GPIBController_Stub& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("VoltOn59", gpib_address);
}




class VoltyMetrics { 
public:
    VoltyMetrics(GPIBController_Stub& controller, int what_address);
    float read();
    // Other member functions go here.
private:
    GPIBController_Stub my_controller;
    int my_gpib_address;
};



float VoltyMetrics::read() {       
    return my_controller.receive(my_gpib_address);
}


// Not shown.
VoltyMetrics::VoltyMetrics(GPIBController_Stub& controller, int what_address) :
  my_controller(controller),
  my_gpib_address(what_address) {
  my_controller.insert("VoltyMetrics", my_gpib_address);
}



float checkCalibration(Acme130& supply, VoltyMetrics& meter, float tst_voltage) {
    // Relative error at specified test voltage.
    supply.set(tst_voltage);
    return abs(tst_voltage - meter.read()) /  tst_voltage;
}


                      
int main() {
GPIBController_Stub gpib;
{

GPIBController_Stub gpib;
Acme130 volt_supply(gpib, 12);// Supply at GPIB address 12.
volt_supply.set(3.6);

cout << "Behavior test done " << endl << endl;
}
{
GPIBController_Stub gpib;


VoltyMetrics meter(gpib, 14);
Acme130      supply1(gpib, 12);

cout << "Acme130 relative error at 1 volt is: " << checkCalibration(supply1, meter, 1.0) << endl;

cout << "Acme130 test done " << endl << endl;
}
{
GPIBController_Stub gpib;


VoltyMetrics meter(gpib, 14);
VoltOn59     supply2(gpib, 17);

// WRONG:
/*
cout << "VoltOn59 relative error at 1 volt is: " << checkCalibration(supply2, meter, 1.0) << endl;

*/
}
  return 0;
}


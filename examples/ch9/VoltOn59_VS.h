/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class VoltOn59_VS :
    public VoltageSupply {
public:         
    VoltOn59_VS(GPIBController_Stub& controller, int gpib_address);

    virtual void  set(float volts);
    virtual float minimum()        const;
    virtual float maximum()        const;

private:        
    GPIBController_Stub my_controller;
    int my_gpib_address;
};


VoltOn59_VS::VoltOn59_VS(GPIBController_Stub& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("VoltOn59_VS", gpib_address);
}


void VoltOn59_VS::set(float volts) {
  my_controller.send(my_gpib_address, volts);
}

float VoltOn59_VS::minimum() const { return 0.0; }
float VoltOn59_VS::maximum() const { return 100.0; }

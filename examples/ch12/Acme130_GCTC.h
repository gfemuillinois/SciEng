/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Acme130GCTCH
#define Acme130GCTCH

#include "examples/ch9/VoltageSupply.h"
#include "examples/ch9/GPIBController.h"
#include "examples/ch9/GPIBInstrument.h"
#include "examples/ch12/GPIBComponent_TC.h"
   

class Acme130_GCTC :            
    public virtual VoltageSupply,

    public virtual GPIBInstrument,
    public         GPIBComponent_TC {

public:         
    virtual Kind kind() const { return Acme130Component; }
    // ... Rest like Acme130_VS_GI_GC...
    Acme130_GCTC(GPIBController& controller, int gpib_address);  
// VoltageSupply interface
    virtual void set(float volts);
    virtual float minimum() const;
    virtual float maximum() const;

// GPIBInstrument interface
    virtual void send(const char*);
    virtual void send(float f);
    virtual float receive();

private:                        
    GPIBController& my_controller;  
    int my_gpib_address;             
};

             
inline float Acme130_GCTC::minimum() const { return 0.0; }
float Acme130_GCTC::maximum() const { return 10.0; }

inline void Acme130_GCTC::send(float value){ 
    my_controller.send(my_gpib_address, value);
}

inline void Acme130_GCTC::send(const char* cmd){ 
    my_controller.send(my_gpib_address, cmd);
}

inline float Acme130_GCTC::receive() { 
    return my_controller.receive(my_gpib_address);
}

inline Acme130_GCTC::Acme130_GCTC(GPIBController& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("Acme130_GCTC", gpib_address);
}

inline void Acme130_GCTC::set(float voltage){ 
    if (voltage > maximum() || voltage < minimum()) throw "Acme 130 voltage out of range";
    send(voltage);
}

#endif

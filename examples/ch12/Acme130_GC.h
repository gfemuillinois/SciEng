/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Acme130GCH
#define Acme130GCH

#include "examples/ch9/VoltageSupply.h"
#include "examples/ch9/GPIBController.h"
#include "examples/ch9/GPIBInstrument.h"
#include "examples/ch12/GPIBComponent.h"

class Acme130_GC;
class GPIBController_GC_GC;


class GPIBComponentAcceptor { 
public:
    virtual void acceptAcme130(const Acme130_GC&) = 0;
    virtual void acceptGPIBController(const GPIBController_GC_GC&) = 0;
    // ...
    virtual ~GPIBComponentAcceptor() {}
};



class Acme130_GC :            
    public virtual VoltageSupply,
    public virtual GPIBInstrument,
    public virtual GPIBComponent {
public:         
    virtual void dispatchTo(GPIBComponentAcceptor& a) const { a.acceptAcme130(*this); }
    // ... Rest like Acme130_VS_GI_GC...
    Acme130_GC(GPIBController& controller, int gpib_address);  
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

             
inline float Acme130_GC::minimum() const { return 0.0; }
inline float Acme130_GC::maximum() const { return 10.0; }

inline void Acme130_GC::send(float value){ 
    my_controller.send(my_gpib_address, value);
}

inline void Acme130_GC::send(const char* cmd){ 
    my_controller.send(my_gpib_address, cmd);
}

inline float Acme130_GC::receive() { 
    return my_controller.receive(my_gpib_address);
}


inline Acme130_GC::Acme130_GC(GPIBController& controller, int gpib_address) : 
    my_controller(controller),
    my_gpib_address(gpib_address) {
    my_controller.insert("Acme130_GC", gpib_address);
}

inline void Acme130_GC::set(float voltage){ 
    if (voltage > maximum() || voltage < minimum()) throw "Acme 130 voltage out of range";
    send(voltage);
}

#endif

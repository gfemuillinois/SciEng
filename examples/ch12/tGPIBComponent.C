/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch12/Acme130_GC.h"
#include "examples/ch12/GPIBComponent.h"
#include "examples/ch12/GPIBController_GC_GC.h"
#include "examples/ch6/List.h"


class GPIBComponentPrinter :
    public GPIBComponentAcceptor {
public:
    virtual void acceptAcme130(const Acme130_GC& p) {
        cout << "An Acme 130 voltage supply; range: " 
            << p.minimum() << "-" << p.maximum() << endl;
    }
    virtual void acceptGPIBController(const GPIBController_GC_GC& p) {
        cout << "A GPIB Controller" << endl;
    }
    // ...
};


void GPIBController_GC_GC::dispatchTo(GPIBComponentAcceptor& p) const {
  p.acceptGPIBController(*this);
}


void addYourComponents(List<GPIBComponent*>& a) { 
    GPIBController_GC_GC* pc = new GPIBController_GC_GC();

    a.add(pc);                       // Public derivation: ok to convert
    a.add(new Acme130_GC(*pc, 12));  // Public derivation: ok to convert

}


int main() {

  List<GPIBComponent*> components;
  addYourComponents(components);
  // At this point, the component types are lost
  
  GPIBComponentPrinter printer;
  for (ListIterator<GPIBComponent*> it(components); it.more(); it.advance()) {
    it.current()->dispatchTo(printer);
}



  for (ListIterator<GPIBComponent*> it(components); it.more(); it.advance()) 
    delete it.current();
  return 0;
}


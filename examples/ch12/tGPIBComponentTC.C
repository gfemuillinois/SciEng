/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch12/Acme130_GCTC.h"
#include "examples/ch12/GPIBController_GC_GCTC.h"
#include "examples/ch6/List.h"


void addYourComponents(List<GPIBComponent_TC*>& a) { 
    GPIBController_GC_GCTC* pc = new GPIBController_GC_GCTC;

    a.add(pc);                       // Public derivation: ok to convert
    a.add(new Acme130_GCTC(*pc, 12));// Public derivation: ok to convert

}


int main() {

List<GPIBComponent_TC*> components;
addYourComponents(components);
// At this point, the component types are lost

for (ListIterator<GPIBComponent_TC*> it(components); it.more(); it.advance()) {
    GPIBComponent_TC* component = it.current();
    GPIBComponent_TC::Kind kind = component->kind();
    if (kind == GPIBComponent_TC::Acme130Component) {
        Acme130_GCTC* p = (Acme130_GCTC*) component;
        cout << "An Acme 130 voltage supply; range: " 
            << p->minimum() << "-" << p->maximum() << endl;
    }
    else if (kind == GPIBComponent_TC::GPIBControllerComponent) {
        GPIBController_GC_GCTC* p = (GPIBController_GC_GCTC*) component;
        cout << "A GPIB Controller" << endl;
    }
}


  for (ListIterator<GPIBComponent_TC*> it(components); it.more(); it.advance()) 
    delete it.current();
return 0;
}

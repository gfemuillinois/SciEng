/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GPIBController_GCH
#define GPIBController_GCH

#include <iostream>
#include "examples/ch9/GPIBController.h"


class GPIBController_GC :
    public GPIBController  {
public:
    virtual void insert(const char* device_name, unsigned int address) { 
        cout << "(" << device_name << " now at address " << address << ")" << endl;
    }
    virtual void send(unsigned int address, const char* cmd) {  
        cout << "(" << "GPIB instrument #" << address << " sends " << cmd << ")" << endl;
    }
    virtual void send(unsigned int address, float f) {  
        cout << "(" << "GPIB instrument #" << address << " sends value " << f << ")" << endl;
    }
    virtual float receive(unsigned int address) { 
        cout << "(" << "Please enter number for GPIB instrument #" << address << ": ";
        float f;
        cin >> f;
        cout << ")" << endl;
        return f;
    }
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GPIBControllerH
#define GPIBControllerH


class GPIBController {
public:
    virtual void insert(const char* device_name, unsigned int address) = 0;
    virtual void send(unsigned int address, const char* cmd) = 0;
    virtual void send(unsigned int address, float f) = 0;
    virtual float receive(unsigned int address) = 0;

    virtual ~GPIBController();
};


#endif

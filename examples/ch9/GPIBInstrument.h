/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GPIBInstrumentH
#define GPIBInstrumentH


class GPIBInstrument { 
public:

    virtual void  send(const char*) = 0;    // Command.
    virtual void  send(float f)     = 0;    // Command with value.
    virtual float receive()         = 0;    // Data point.


    virtual ~GPIBInstrument();
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GPIBComponentH
#define GPIBComponentH


class GPIBComponentAcceptor;  // See below.

class GPIBComponent { // Base class for lists of GPIB components 
public:
    virtual void dispatchTo(GPIBComponentAcceptor&) const = 0;
    virtual ~GPIBComponent() {}
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GPIBComponentTC
#define GPIBComponentTC


class GPIBComponent_TC {
public:
    enum Kind { Acme130Component, GPIBControllerComponent /* ... */ };
    virtual Kind kind() const = 0;
    virtual ~GPIBComponent_TC() {}
};


#endif

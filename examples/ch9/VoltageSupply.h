/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef VoltageSupplyH
#define VoltageSupplyH


class VoltageSupply { 
public:

    virtual void  set(float volts)       = 0;
    virtual float minimum()        const = 0;
    virtual float maximum()        const = 0;


    virtual ~VoltageSupply();
};


#endif

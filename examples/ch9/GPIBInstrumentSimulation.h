/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GPIBInstrumentSimulationH
#define GPIBInstrumentSimulationH


class GPIBInstrumentSimulation { 
public:

    virtual void  send(const char*) = 0;
    virtual void  send(float f) = 0;
    virtual float receive() = 0;


    virtual ~GPIBInstrumentSimulation();
};


#endif


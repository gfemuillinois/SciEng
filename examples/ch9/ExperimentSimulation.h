/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ExperimentSimulationH
#define ExperimentSimulationH


class ExperimentSimulation { 
public:

    void   apply(double voltage);    // Called by voltage supply simulation.
    double test();                   // Called by voltmeter simulation.

private:
    double the_voltage;
};


#endif

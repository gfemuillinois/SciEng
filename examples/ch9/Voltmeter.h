/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef VoltmeterH
#define VoltmeterH

// Not Shown
class Voltmeter {
public:
 virtual float read() = 0;
 virtual ~Voltmeter();
};

#endif

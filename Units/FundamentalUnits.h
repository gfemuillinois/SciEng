/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FundamentalUnitsH
#define FundamentalUnitsH

#include "Units/Physical.h"

// Systeme International Unites, extended MKS

template<class T>
class FundamentalUnits { 
public:

    typedef Physical<T, 1, 0, 0, 0, 0, 0, 0> Mass;
    typedef Physical<T, 0, 1, 0, 0, 0, 0, 0> Length;
    typedef Physical<T, 0, 0, 1, 0, 0, 0, 0> Time;
    typedef Physical<T, 0, 0, 0, 1, 0, 0, 0> Charge;
    typedef Physical<T, 0, 0, 0, 0, 1, 0, 0> Temperature;
    typedef Physical<T, 0, 0, 0, 0, 0, 1, 0> Intensity;
    typedef Physical<T, 0, 0, 0, 0, 0, 0, 1> Angle;

};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DerivedUnitsH
#define DerivedUnitsH

#include "Units/FundamentalUnits.h"

// Systeme International Unites, extended MKS

template<class T>
class DerivedUnits :
    public FundamentalUnits<T> {
public:

    typedef Physical<T, 0, 1, -1, 0, 0, 0, 0> Velocity;
    typedef Physical<T, 0, 1, -2, 0, 0, 0, 0> Acceleration;
    typedef Physical<T, 1, 1, -2, 0, 0, 0, 0> Force;
    typedef Physical<T, 1, 2, -2, 0, 0, 0, 0> Energy;
    // ...

};


#endif

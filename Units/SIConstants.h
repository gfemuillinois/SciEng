/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SIConstantsH
#define SIConstantsH

#include "Units/DerivedUnits.h"


template<class T>
class SIConstants :
    public DerivedUnits<T> {
public:
  typedef typename FundamentalUnits<T>::Mass     Mass;
  typedef typename FundamentalUnits<T>::Length   Length;
  typedef typename DerivedUnits<T>::Force        Force;
  typedef typename FundamentalUnits<T>::Time     Time;  
  typedef typename DerivedUnits<T>::Acceleration Acceleration;

    static const Mass         kilogram;
    static const Length       meter;
    static const Force        newton;
    static const Time         second;
    static const Acceleration meter_per_sec2;
    static const Acceleration g;
    // ...
};


#ifdef XLC_QNOTEMPINC
#include "Units/SIConstants.c"
#endif
#endif

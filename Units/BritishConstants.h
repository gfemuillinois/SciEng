/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef BritishConstantsH
#define BritishConstantsH

#include "Units/SIConstants.h"

template<class T>
class BritishConstants :
    public SIConstants<T> {
public:
  typedef SIConstants<T>::Mass     Mass;
  typedef SIConstants<T>::Length   Length;
  typedef SIConstants<T>::Force    Force;
  typedef SIConstants<T>::Acceleration Acceleration;

    static const Mass slug;
    static const Length foot;
    static const Length inch;
    static const Force pound;
    static const Acceleration ft_per_sec2;
};

#ifdef XLC_QNOTEMPINC
#include "Units/BritishConstants.c"
#endif

#endif

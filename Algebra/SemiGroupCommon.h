/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SemiGroupCommonH
#define SemiGroupCommonH

#include "Algebra/Positive.h"


template<class T, class Structure>
class SemiGroupCommon {              
public:
    static T& repeatedComposition(T& x, Positive<int> n);
};


#ifdef XLC_QNOTEMPINC
#include "Algebra/SemiGroupCommon.c"
#endif

#endif

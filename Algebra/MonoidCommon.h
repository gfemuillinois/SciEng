/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MonoidCommonH                                           
#define MonoidCommonH                                           

#include "Algebra/NonNegative.h"

template<class T, class Structure> 
class MonoidCommon {
public:
 static T& repeatedComposition(T& x, NonNegative<int> n);
};

#ifdef XLC_QNOTEMPINC
#include "Algebra/MonoidCommon.c"
#endif

#endif

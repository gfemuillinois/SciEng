/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GroupCommonH
#define GroupCommonH

#include "Algebra/MonoidCommon.h"

template<class T, class Structure>
class GroupCommon {
public:
 static T& repeatedComposition(T& x, int n);
};

#ifdef XLC_QNOTEMPINC
#include "Algebra/GroupCommon.c"
#endif

#endif

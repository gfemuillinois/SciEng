/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayCheckH
#define ArrayCheckH

template<class Array>
void check(const Array&, const char*);

#ifdef XLC_QNOTEMPINC
#include "Array/ArrayCheck.c"
#endif

#endif

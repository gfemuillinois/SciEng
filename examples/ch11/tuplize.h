/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef tuplizeH
#define tuplizeH
#include<iosfwd>

template<class T> class SimpleArray;

template<class T>
std::ostream& tuplize(std::ostream& os, const SimpleArray<T>& a);

#ifdef XLC_QNOTEMPINC
#include "examples/ch11/tuplize.c"
#endif

#endif

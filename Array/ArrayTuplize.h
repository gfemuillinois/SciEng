/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayTuplizeH
#define ArrayTuplizeH

class ostream;

template<class Array>
ostream& arrayTuplize(const Array& a, ostream& os);

#ifdef XLC_QNOTEMPINC
#include "Array/ArrayTuplize.c"
#endif

#endif

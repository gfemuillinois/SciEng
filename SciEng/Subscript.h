/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SubscriptH
#define SubscriptH

#include <cstddef>

//namespace SciEngLib{

typedef unsigned short int Dimension;
//typedef ptrdiff_t          Subscript64;  // Signed, machine-dependent int; from <stddef.h>
typedef int                Subscript;    // Signed int


// Right now, this is only used inside of class PardisoSolver
// Version 10 of MKL has Pardiso with all int arguments of type long long

#if defined(MKL_ILP64)
typedef  long long        Subscript64;
#else
typedef  int              Subscript64;
#endif

//}

#endif

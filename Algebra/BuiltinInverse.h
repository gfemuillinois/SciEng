/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef BuiltinInverseH
#define BuiltinInverseH

inline double inverse(double d) { return 1 / d; }
inline float inverse(float f) { return 1 / f; }

#ifdef COMPLEXH
inline complex inverse(complex c) { return complex(1) / c; }
#endif
#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributingMetricSpaceH
#define DistributingMetricSpaceH
                                    
template<class Array, class M>
class DistributingMetricSpace {
public:
  M dot(const Array& rhs) const;
};

inline double dot(double lhs, double rhs) { return lhs * rhs; }

#ifdef COMPLEXH
inline double dot(complex lhs, complex rhs) { return real(lhs) * real(rhs) + imag(lhs) * imag(lhs); }
#endif

#ifdef XLC_QNOTEMPINC
#include "Vector/DistributingMetricSpace.c"
#endif

#endif

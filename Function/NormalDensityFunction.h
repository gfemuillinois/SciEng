/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NormalDensityFunctionH
#define NormalDensityFunctionH

#include "Function/Functional.h"


template <class D>
class NormalDensityFunction { 
public:
    NormalDensityFunction(const D& mean, const D& std_dev);

    D& mean()  { return the_mean;    }
    D& width() { return the_std_dev; }

    D operator()(const D& x) const;
protected:
    D the_mean;
    D the_std_dev;
};


template<class D>
inline NormalDensityFunction<D>::
NormalDensityFunction(const D& mean, const D& std_dev) :
    the_mean(mean),
    the_std_dev(std_dev) {
}

#ifdef XLC_QNOTEMPINC
#include "Function/NormalDensityFunction.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef GaussianFunctionH
#define GaussianFunctionH

#include "Function/Functional.h"


template <class D>
class GaussianFunction :      
    public virtual Functional<D,D> {
public:
    GaussianFunction(const D& mean, const D& width);

    D& mean()  { return the_mean;  }

    virtual D operator()(const D& x) const;
protected:
    D the_mean;
    D the_width;
};


template<class D>
inline
GaussianFunction<D>::GaussianFunction(const D& mean, const D& width) :
  the_mean(mean),
  the_width(width) {
}

#ifdef XLC_QNOTEMPINC
#include "Function/GaussianFunction.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include "SciEng/utils.h"


template<class D>
D NormalDensityFunction<D>::operator()(const D& x) const {
    const double recip_sqrt_2_pi = .3989423;
    const double recip_std_dev = 1.0 / the_std_dev;
    return recip_std_dev * recip_sqrt_2_pi * exp( -.5 * sqr((x - the_mean) * recip_std_dev) );
}


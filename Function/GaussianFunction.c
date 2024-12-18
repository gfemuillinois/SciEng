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
D GaussianFunction<D>::operator()(const D& x) const {
    return exp(- sqr( (x-the_mean) / the_width ) );
}

      

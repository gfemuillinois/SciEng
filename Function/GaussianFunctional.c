/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Function/ConstantFunctional.h"
template<class Domain>
GaussianFunctional<Domain>:: GaussianFunctional(const Domain& mean, const Domain& width) :
    the_mean(
      CopyableNewPtr<IsoFunctional<Domain> > (
         new ConstantFunctional<Domain>(mean) 
      )
    ),
    the_width(
      CopyableNewPtr<IsoFunctional<Domain> > (
         new ConstantFunctional<Domain>(width)
      )
    ) {
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LegendrePolynomialH
#define LegendrePolynomialH

#include "Function/FunctionalAlgebra.h"


template<class D>
class LegendrePolynomial :
    public FunctionalAlgebra<D> {
public:
    LegendrePolynomial(int n = 0);
private:
    static FunctionalAlgebra<D> recur(int n);
};

#ifdef XLC_QNOTEMPINC
#include "Function/LegendrePolynomial.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/NumericalLimits.h"



template<class Rep>
NormalizedLapackFactored<Rep>
NormalizedLapackUnfactored<Rep>::factor(){   
    ColumnNorms<Rep::Unfactored>* column_scalars = new ColumnNorms<Rep::Unfactored>(rep());  // The matrix F as a vector.
    column_scalars->normalize(rep());
    return  NormalizedLapackFactored<Rep>(new Rep::Factored( releaseControl() ), column_scalars );
}




template<class Rep>
NormalizedLapackFactored<Rep>::Unknowns1d&
NormalizedLapackFactored<Rep>::solve(NormalizedLapackFactored<Rep>::Unknowns1d& b){ 
    rep().solve(b);
    normalize(b, *column_scalars);
    return b;
}


template<class Rep>
NormalizedLapackFactored<Rep>::Unknowns1d&
NormalizedLapackFactored<Rep>::solve(
        NormalizedLapackFactored<Rep>::Unknowns1d& x, 
        const NormalizedLapackFactored<Rep>::Knowns1d& b
   ){ 
    rep().solve(x,b);
    normalize(x, *column_scalars);
    return x;
}

template<class Rep>
NormalizedLapackFactored<Rep>::Unknowns2d&
NormalizedLapackFactored<Rep>::solve(NormalizedLapackFactored<Rep>::Unknowns2d& x){ 
    rep().solve(x);
    for(Subscript ith_col = 0; ith_col < x.shape(1); ith_col++) {
    //BlasProjection1d<EltT> c(x.column(ith_col));
    normalize(x.column(ith_col), *column_scalars);
    }
    return x;
}

template<class Rep>
NormalizedLapackFactored<Rep>::Unknowns2d&
NormalizedLapackFactored<Rep>::solve(
    NormalizedLapackFactored<Rep>::Unknowns2d& x,
    const NormalizedLapackFactored<Rep>::Knowns2d& b
  ){ 
    rep().solve(x,b);
    for(Subscript ith_col = 0; ith_col < x.shape(1); ith_col++) {
    //BlasProjection1d<EltT> c(x.column(ith_col));
    normalize(x.column(ith_col), *column_scalars);
    }
    return x;
}

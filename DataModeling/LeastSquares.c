/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/NumericalLimits.h"
#include "Array/arrayCopy.h"
#include "SciEng/utils.h"

template<class A>
LeastSquares<A>&
LeastSquares<A>::operator=(const LeastSquares<A>& rhs){
  // This works around a compiler bug.
  A& lhs = *this;
  lhs = rhs;
  b = rhs.b;
  the_chi2 = rhs.the_chi2;
  return *this;
}


template<class A>
LeastSquares<A>::LeastSquares( 
    const PhysicalData<EltT>& data,
    const Functional<EltT, TaylorCoefficient1d<EltT> >& model,
    Subscript nparms
) :
    A(data.numElts(), nparms),
    b( data.numElts() ),
    the_chi2( EltT(0) ) {

    AccessedPhysicalDataBrowser<EltT> data_b = data.browser();

    ConcreteBlas2d<EltT>& a_matrix = rep(); // Connect to base class matrix.
    for (Subscript i = 0; data_b.more(); i++) { 
        TaylorCoefficient1d<EltT> model_i = model( data_b.coordinate() );


        EltT recip_sigma_i  = EltT(1) / data_b.sigma();
        EltT delta_i        = ( data_b.value() - model_i.value() ) * recip_sigma_i;
        b(i)                = delta_i;
        the_chi2           += sqr(delta_i);


        arrayCopy(a_matrix.row(i),  model_i);  // Load gradients into rows of matrix.
        a_matrix.row(i) *= recip_sigma_i;

        data_b.advance();
    }
}


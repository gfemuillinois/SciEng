/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/NumericalLimits.h"

template<class Range>
LevenbergMarquardtHessian<Range>::
LevenbergMarquardtHessian( Subscript nparms ) :
    LapackUnfactored< BlasRectLURep<Range> >(nparms,nparms), // square system for normal equations.
    b(nparms),
    the_chi2(NumericalLimits<Range>::maximum) {  
}


template<class Range>
void LevenbergMarquardtHessian<Range>::doMarquardt(Range factor){
    for (int i = 0; i < shape(0); i++){
       (*this)(i,i) *= factor;
    }                                         
}

template<class T>
ConcreteBlas2d<T> outer_product(const Array1d<T>& lhs, const Array1d<T>& rhs){
   Subscript nrows = lhs.numElts();
   Subscript ncols = rhs.numElts();
   
   ConcreteBlas2d<T> result(nrows, ncols);
   
   for(int i = 0; i < nrows; i++) {
     for(int j = 0; j < ncols; j++) {
       result(i,j) = lhs(i) * rhs(j);
     }
   }
   return result;
}

/*
   We
   minimize over \vec{a} \sigma_{i=1}^{N} \rho\left ( \frac{y_i - y(x_i;\vec{a})}{\sigma_i} \right )
 
*/
#include "Vector/FormedArithmetic.h"
 
template<class Range>
LevenbergMarquardtHessian<Range>::
LevenbergMarquardtHessian(
    const PhysicalData<Range>& the_data,
    const DataModel<Range>& the_model
  ):
  LapackUnfactored< BlasRectLURep<Range> >(
    the_model.parameters().numElts(),the_model.parameters().numElts() // square system for normal equations.
  ),
  b(the_model.parameters().numElts()),
  the_chi2(NumericalLimits<Range>::maximum) {

  Browser<Range> coordinates = the_data.coordinates();     // x_i
  Browser<Range> data        = the_data.values();          // y_i
  Browser<Range> sigma       = the_data.sigmas();          // sigma_i
  
  the_chi2 = 0.;
  
  // Temps.
  BlasRectLURep<Range>::Unfactored& alpha = rep();
  alpha = 0.;
  FormedArithmetic1d<Range> beta(the_model.parameters().numElts());
  beta = 0.;
  FormedArithmetic1d<Range> dy_da(the_model.parameters().numElts());
  Range delta_i;
  
  while( coordinates.more() && data.more() && sigma.more() ){
  
    Range the_sigma_i = sigma();
    
    BasePtr< TaylorCoefficient1d<Range> > the_model_i = the_model(coordinates());
    
    dy_da = the_model_i->gradient();
                                                                                        
    delta_i = ( data() - the_model_i->value() ) / the_sigma_i;
    
    the_chi2 += delta_i * delta_i * 0.5;  // Numerical Recipes 14.6.3
    
    beta -= delta_i * dy_da / the_sigma_i;

    alpha += outer_product(dy_da, dy_da) / (the_sigma_i * the_sigma_i);

    coordinates.next();
    data.next();
    sigma.next();
  }
  b = beta;
}

 

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LevenbergMarquardtHessianH
#define LevenbergMarquardtHessianH

#include "DataModeling/PhysicalData.h"
#include "LapackWrap/Lapack.h"
#include "LapackWrap/BlasRectLURep.h"
#include "SciEng/NumericalLimits.h"

template<class Range>
class LevenbergMarquardtHessian :
  public virtual Array2d<Range>,
  private LapackUnfactored< BlasRectLURep<Range> > {
public:
  LevenbergMarquardtHessian(
    const PhysicalData<Range>& the_data,
    const DataModel<Range>& the_model
    );
  LevenbergMarquardtHessian(Subscript nparms);  // empty.
  
  LapackUnfactored< BlasRectLURep<Range> >::factor;
  LapackUnfactored< BlasRectLURep<Range> > ::rep;
  
  LapackUnfactored< BlasRectLURep<Range> > ::dim;
  LapackUnfactored< BlasRectLURep<Range> > ::shape;
  LapackUnfactored< BlasRectLURep<Range> > ::numElts;
  LapackUnfactored< BlasRectLURep<Range> > ::operator[];
  LapackUnfactored< BlasRectLURep<Range> > ::operator();
  
  Range chi2() { return the_chi2; }
  void doMarquardt(Range factor);  // bias jacobian diagonal by fudge factor
  
  LevenbergMarquardtHessian<Range>&  operator=(const LevenbergMarquardtHessian<Range>& rhs){
    LapackUnfactored< BlasRectLURep<Range> >::operator=(rhs);
    return *this;
  }
  
private:
  BlasRectLURep<Range>::Knowns1d b;  // right hand side of Ax = b;
  Range the_chi2;
};

#ifdef XLC_QNOTEMPINC
#include "DataModeling/LevenbergMarquardtHessian.c"
#endif

#endif

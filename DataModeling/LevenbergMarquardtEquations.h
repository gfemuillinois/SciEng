/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LevenbergMarquardtEquationsH
#define LevenbergMarquardtEquationsH


#include "DataModeling/IteratedEquations.h"
#include "DataModeling/LinearizedEquationsBase.h"
#include "SciEng/Ptrs.h"
#include "DataModeling/DataModel.h"
#include "DataModeling/LevenbergMarquardtHessian.h"

template<class Range>
class LevenbergMarquardtEquations :
  public virtual IteratedEquations< Range >,
  private LinearizedEquationsBase<Range> {
public:
  LevenbergMarquardtEquations(const PhysicalData<Range>& data_to_fit, const DataModel<Range>& model);
  LinearizedEquationsBase<Range>::initialValues;
  virtual Range  update(Array1d<Range>&);
  LinearizedEquationsBase<Range>::converged;
private:
  Range lamda;
  LevenbergMarquardtHessian<Range> hessian;
};

#ifdef XLC_QNOTEMPINC
#include "DataModeling/LevenbergMarquardtEquations.c"
#endif

#endif


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MatrixCategoryH
#define MatrixCategoryH

#include "Algebra/FieldScalarsCategory.h"
#include "Algebra/DivisionAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"
#include "Array/Array1d.h"
#include "Array/Array2d.h"


template<class M, class V, class S>
class MatrixCategory :
  public Array2d<S>,
  public DivisionAlgebraCategory<M,S>,
  public FieldScalarsCategory<M,V> {
public:
  virtual S norm() = 0;  // Different norms possible, as well as different ways of computing them.
  typedef V Vectors;
};

template<class M, class V, class S>
class VectorUnderMatrix :
  public Array1d<S>,
  public LinearSpaceCategory<V,S>,
  public MetricSpaceCategory<V,S> {
public:
  M outer_product(const VectorUnderMatrix<M,V,S>&) const;
  friend M outer_product(const V& lhs, const V& rhs){ return lhs.outer_product(rhs); }
};

#ifdef XLC_QNOTEMPINC
#include "Vector/MatrixCategory.c"
#endif
      
#endif

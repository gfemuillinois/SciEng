/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MetricRigidArithmeticH
#define MetricRigidArithmeticH

#include "Algebra/DivisionAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"
#include "Vector/DistributingDivisionAlgebra.h"
#include "Vector/DistributingMetricSpace.h"
#include "Array/RigidArray.h"


template<class T, Subscript n0>
class MetricRigidArithmetic1d :            
    public DivisionAlgebraCategory< MetricRigidArithmetic1d<T, n0>, T >,
    public MetricSpaceCategory< MetricRigidArithmetic1d<T, n0>, double>,
    public DistributingDivisionAlgebra<MetricRigidArithmetic1d<T, n0>,T>,
    public DistributingMetricSpace<MetricRigidArithmetic1d<T, n0>, double>,
    public RigidArray1d<T, n0>                                     {
public:
    MetricRigidArithmetic1d() : RigidArray1d<T, n0>() {}
    //MetricRigidArithmetic1d(Subscript n) : RigidArray1d<T, n0>(n) {}

    const MetricRigidArithmetic1d<T, n0>& operator=(const Array<T>& rhs) { 
        RigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
    const MetricRigidArithmetic1d<T, n0>& operator=(const MetricRigidArithmetic1d<T, n0>& rhs) {
        RigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
    const MetricRigidArithmetic1d<T, n0>& operator=(const T& rhs) {
        RigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
};



template<class T, Subscript n0, Subscript n1>
class MetricRigidArithmetic2d :
  public DivisionAlgebraCategory< MetricRigidArithmetic2d<T, n0, n1>, T >,
  public DistributingDivisionAlgebra<MetricRigidArithmetic1d<T, n0, n1>, T>,
  public RigidArray2d<T, n0, n1>                                     {
public:
  MetricRigidArithmetic2d(Subscript n1, Subscript n2) :
      RigidArray2d<T, n0, n1>(n1, n2) {}
  const MetricRigidArithmetic2d<T, n0, n1>& operator=(const StridedArray<T, 2>& rhs) {
    RigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }
  const MetricRigidArithmetic2d<T, n0, n1>& operator=(const MetricRigidArithmetic2d<T, n0, n1>& rhs) {
    RigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }
  const MetricRigidArithmetic2d<T, n0, n1>& operator=(const T& rhs) {
    RigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }
};

#endif

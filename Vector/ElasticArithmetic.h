/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ElasticArithmeticH
#define ElasticArithmeticH

#include "Algebra/DivisionAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"
#include "Vector/DistributingDivisionAlgebra.h"
#include "Vector/DistributingMetricSpace.h"
#include "Vector/DistributingEquivalentCategory.h"
#include "Array/FormedArray.h"

// CAD 
// Similar to class FormedArithmetic1d from file FormedArithmetic.h
//

template<class T>
class ElasticArithmetic1d :            
    public DivisionAlgebraCategory< ElasticArithmetic1d<T>, T >,
    public DistributingDivisionAlgebra<ElasticArithmetic1d<T>, T, T>,
    public DistributingEquivalentCategory< ElasticArithmetic1d<T> >,
    public ConcreteFormedArray1d<T>                                     {
public:
    explicit ElasticArithmetic1d(Subscript n) : ConcreteFormedArray1d<T>(n) {}
    ElasticArithmetic1d(const Array1d<T>& a);
    ElasticArithmetic1d(const ConcreteFormedArray1d<T>& a) : ConcreteFormedArray1d<T>(a) {}
    ElasticArithmetic1d(const ElasticArithmetic1d<T>& a) : ConcreteFormedArray1d<T>(a) {}
    ElasticArithmetic1d() {}

    // These assignments expand or contract to accomdate rhs.
    const ElasticArithmetic1d<T>& operator=(const Array1d<T>& rhs);
    const ElasticArithmetic1d<T>& operator=(const ElasticArithmetic1d<T>& rhs) {
        reshape(rhs.shape(0));
        ConcreteFormedArray1d<T>::operator=(rhs);
        return *this;
    }
    const ElasticArithmetic1d<T>& operator=(const T& rhs) {
        ConcreteFormedArray1d<T>::operator=(rhs);
        return *this;
    }

    void reshape(const SubscriptArray<1>& ea);  // Pads with T(0.).

    typedef DistributingDivisionAlgebra<ElasticArithmetic1d<T>, T, T> AlgebraicParent;

    ElasticArithmetic1d<T>& operator+=(const ElasticArithmetic1d<T>& rhs) {
      reshape(SubscriptArray<1>(rhs.shape(0)));
      return AlgebraicParent::operator+=(rhs); 
    }
    ElasticArithmetic1d<T>& operator-=(const ElasticArithmetic1d<T>& rhs) {
      reshape(SubscriptArray<1>(rhs.shape(0)));
      return AlgebraicParent::operator-=(rhs);
    }
    ElasticArithmetic1d<T>& operator*=(const ElasticArithmetic1d<T>& rhs) {
      reshape(SubscriptArray<1>(rhs.shape(0)));
      return AlgebraicParent::operator*=(rhs);
    }
    ElasticArithmetic1d<T>& operator/=(const ElasticArithmetic1d<T>& rhs) {
      reshape(SubscriptArray<1>(rhs.shape(0)));
      return AlgebraicParent::operator/=(rhs);
    }
    ElasticArithmetic1d<T>& operator*=(const T& rhs) { return AlgebraicParent::operator*=(rhs); }
    ElasticArithmetic1d<T>& operator/=(const T& rhs) { return AlgebraicParent::operator/=(rhs); }
};



template<class T>
class ElasticArithmetic2d :
  public DivisionAlgebraCategory< ElasticArithmetic2d<T>, T >,
  public DistributingDivisionAlgebra<ElasticArithmetic2d<T>, T, T>,
  public ConcreteFormedArray2d<T>                                     {
public:
  ElasticArithmetic2d(Subscript n1, Subscript n2) :
      ConcreteFormedArray2d<T>(n1, n2) {}
  ElasticArithmetic2d() {}
  
  const ElasticArithmetic2d<T>& operator=(const StridedArray<T, 2>& rhs) {
    reshape(rhs.shape());
    ConcreteFormedArray2d<T>::operator=(rhs);
    return *this;
  }
  const ElasticArithmetic2d<T>& operator=(const ElasticArithmetic2d<T>& rhs) {
    reshape(rhs.shape());
    ConcreteFormedArray2d<T>::operator=(rhs);
    return *this;
  }
  const ElasticArithmetic2d<T>& operator=(const T& rhs) {
    ConcreteFormedArray2d<T>::operator=(rhs);
    return *this;
  }
  typedef DistributingDivisionAlgebra<ElasticArithmetic2d<T>, T, T> AlgebraicParent;
  ElasticArithmetic2d<T>& operator+=(const ElasticArithmetic2d<T>& rhs) {
    reshape(SubscriptArray<2>(rhs.shape(0), rhs.shape(1)));
    return AlgebraicParent::operator+=(rhs); 
  }
  ElasticArithmetic2d<T>& operator-=(const ElasticArithmetic2d<T>& rhs) {
    reshape(SubscriptArray<2>(rhs.shape(0), rhs.shape(1)));
    return AlgebraicParent::operator-=(rhs);
  }
  ElasticArithmetic2d<T>& operator*=(const ElasticArithmetic2d<T>& rhs) {
    reshape(SubscriptArray<2>(rhs.shape(0), rhs.shape(1)));
    return AlgebraicParent::operator*=(rhs);
  }
  ElasticArithmetic2d<T>& operator/=(const ElasticArithmetic2d<T>& rhs) {
    reshape(SubscriptArray<2>(rhs.shape(0), rhs.shape(1)));
    return AlgebraicParent::operator/=(rhs);
  }
  ElasticArithmetic2d<T>& operator*=(const T& rhs) { return AlgebraicParent::operator*=(rhs); }
  ElasticArithmetic2d<T>& operator/=(const T& rhs) { return AlgebraicParent::operator/=(rhs); }
};

#ifdef XLC_QNOTEMPINC
#include "Vector/ElasticArithmetic.c"
#endif

#endif

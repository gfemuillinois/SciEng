/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedArithmeticH
#define FormedArithmeticH

#include "Algebra/DivisionAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"

#include "Vector/DistributingDivisionAlgebra.h"
#include "Vector/DistributingMetricSpace.h"
#include "Vector/DistributingEquivalentCategory.h"

#include "Array/FormedArray.h"


template<class T>
class FormedArithmetic1d :            
    public DivisionAlgebraCategory< FormedArithmetic1d<T>, T >,
    public MetricSpaceCategory< FormedArithmetic1d<T>, double>,

    public DistributingDivisionAlgebra<FormedArithmetic1d<T>, T, T>,
    public DistributingEquivalentCategory<FormedArithmetic1d<T> >,
    public DistributingMetricSpace< FormedArithmetic1d<T>, double>,

    public ConcreteFormedArray1d<T>                                     {
public:
    explicit FormedArithmetic1d(Subscript n) : ConcreteFormedArray1d<T>(n) {}
    FormedArithmetic1d() {}
    FormedArithmetic1d(const FormedArithmetic1d<T>& a)  : ConcreteFormedArray1d<T>(a) {}

    const FormedArithmetic1d<T>& operator=(const Array1d<T>& rhs);
    const FormedArithmetic1d<T>& operator=(const FormedArithmetic1d<T>& rhs) {
        ConcreteFormedArray1d<T>::operator=(rhs);
        return *this;
    }
    const FormedArithmetic1d<T>& operator=(const T& rhs) {
        ConcreteFormedArray1d<T>::operator=(rhs);
        return *this;
    }
};



template<class T>
class FormedArithmetic2d :
  public DivisionAlgebraCategory< FormedArithmetic2d<T>, T >,

  public DistributingDivisionAlgebra< FormedArithmetic2d<T>, T, T>,
  public DistributingEquivalentCategory< FormedArithmetic2d<T> >,

  public ConcreteFormedArray2d<T>                                     {
public:
  FormedArithmetic2d(Subscript n1, Subscript n2) : 
    ConcreteFormedArray2d<T>(n1, n2) {}
  FormedArithmetic2d() {}
  
  const FormedArithmetic2d<T>& operator=(const FormedArithmetic2d<T>& rhs) {
    ConcreteFormedArray2d<T>::operator=(rhs);
    return *this;
  }
  const FormedArithmetic2d<T>& operator=(const T& rhs) {
    ConcreteFormedArray2d<T>::operator=(rhs);
    return *this;
  }
};

#endif

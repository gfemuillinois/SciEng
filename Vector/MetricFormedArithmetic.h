/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MetricFormedArithmeticH
#define MetricFormedArithmeticH

#include "Algebra/DivisionAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"
#include "Vector/DistributingDivisionAlgebra.h"
#include "Vector/DistributingMetricSpace.h"
#include "Array/FormedArray.h"

template<class T,class M>
class MetricFormedArithmetic1d :            
    public DivisionAlgebraCategory< MetricFormedArithmetic1d<T, M>, T >,
    public MetricSpaceCategory< MetricFormedArithmetic1d<T, M>, M>,
    public DistributingDivisionAlgebra<MetricFormedArithmetic1d<T, M>,T, T>,
    public DistributingMetricSpace<MetricFormedArithmetic1d<T, M>, M>,
    public ConcreteFormedArray1d<T>                                     {
public:
    MetricFormedArithmetic1d(Subscript n) : ConcreteFormedArray1d<T>(n) {}
    MetricFormedArithmetic1d(const MetricFormedArithmetic1d<T, M>& a) : ConcreteFormedArray1d<T>(a) {}

    const MetricFormedArithmetic1d<T, M>& operator=(const Array1d<T>& rhs);
    const MetricFormedArithmetic1d<T, M>& operator=(const MetricFormedArithmetic1d<T, M>& rhs) {
                                                                      ConcreteFormedArray1d<T>::operator=(rhs);
                                                                      return *this;
    }
    const MetricFormedArithmetic1d<T, M>& operator=(const T& rhs) {
                                                                      ConcreteFormedArray1d<T>::operator=(rhs);
                                                                      return *this;
    }
};

#endif

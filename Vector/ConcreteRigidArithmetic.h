/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteRigidArithmeticH
#define ConcreteRigidArithmeticH

#include "Algebra/DivisionAlgebraCategory.h"
#include "Vector/DistributingDivisionAlgebra.h"
#include "Array/ConcreteRigidArray1d.h"

template<class T, Subscript n0>
class ConcreteRigidArithmetic :            
    public DivisionAlgebraCategory< ConcreteRigidArithmetic<T, n0>, T >,
    public DistributingDivisionAlgebra<ConcreteRigidArithmetic<T, n0>,T>,
    public ConcreteRigidArray1d<T, n0>                                     {
public:
    ConcreteRigidArithmetic() : ConcreteRigidArray1d<T, n0>() {}
    ConcreteRigidArithmetic(Subscript n) : ConcreteRigidArray1d<T, n0>(n) {}

    ConcreteRigidArithmetic<T, n0>& operator/=(const ConcreteRigidArithmetic<T, n0>& rhs) {
    DistributingDivisionAlgebra<ConcreteRigidArithmetic<T, n0>,T>::operator/=(rhs); 
    return *this;
    }
    const ConcreteRigidArithmetic<T, n0>& operator=(const ConcreteRigidArithmetic<T, n0>& rhs) {
        ConcreteRigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
    const ConcreteRigidArithmetic<T, n0>& operator=(const T& rhs) {
        ConcreteRigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
};

#endif

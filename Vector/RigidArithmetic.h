/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidArithmeticH
#define RigidArithmeticH

#include "Algebra/DivisionAlgebraCategory.h"
#include "Vector/DistributingDivisionAlgebra.h"
#include "Vector/DistributingEquivalentCategory.h"
#include "Array/RigidArray.h"


template<class T, Subscript n0>
class RigidArithmetic1d :            
    public DivisionAlgebraCategory< RigidArithmetic1d<T, n0>, T >,
    public DistributingDivisionAlgebra<RigidArithmetic1d<T, n0>,T, T>,
    public DistributingEquivalentCategory<RigidArithmetic1d<T, n0> >,
    public ConcreteRigidArray1d<T, n0> {
public:
    RigidArithmetic1d() : ConcreteRigidArray1d<T, n0>() {}
    RigidArithmetic1d(Subscript n) : ConcreteRigidArray1d<T, n0>(n) {}
    RigidArithmetic1d(const RigidArithmetic1d<T, n0>& a) : ConcreteRigidArray1d<T, n0>(a) {}

    const RigidArithmetic1d<T, n0>& operator=(const RigidArithmetic1d<T, n0>& rhs) {
        ConcreteRigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
    const RigidArithmetic1d<T, n0>& operator=(const T& rhs) {
        ConcreteRigidArray1d<T, n0>::operator=(rhs);
        return *this;
    }
};



template<class T, Subscript n0, Subscript n1>
class RigidArithmetic2d :
  public DivisionAlgebraCategory< RigidArithmetic2d<T, n0, n1>, T >,
  public DistributingDivisionAlgebra<RigidArithmetic2d<T, n0, n1>, T>,
  public ConcreteRigidArray2d<T, n0, n1>                                     {
public:
  RigidArithmetic2d(Subscript n1, Subscript n2) :
      ConcreteRigidArray2d<T, n0, n1>(n1, n2) {}
      
  const RigidArithmetic2d<T, n0, n1>& operator=(const RigidArithmetic2d<T, n0, n1>& rhs) {
    ConcreteRigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }
  const RigidArithmetic2d<T, n0, n1>& operator=(const T& rhs) {
    ConcreteRigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }
};

#endif

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
#include "Algebra/MetricSpaceCategory.h"

#include "Vector/DistributingDivisionAlgebra.h"
#include "Vector/DistributingEquivalentCategory.h"
#include "Vector/DistributingMetricSpace.h"

#include "Array/ConcreteRigidArray.h"

template<class T, Subscript n0> class RigidArithmetic1d;

template<class T>
void crossProd(const RigidArithmetic1d<T, 3>& a, 
	       const RigidArithmetic1d<T, 3>& b, 
	       RigidArithmetic1d<T, 3>& c);

template<class T, Subscript n0>
class RigidArithmetic1d :            
  public DivisionAlgebraCategory< RigidArithmetic1d<T, n0>, T >,
  public MetricSpaceCategory< RigidArithmetic1d<T, n0>, double>,

  public DistributingDivisionAlgebra<RigidArithmetic1d<T, n0>,T, T>,
  public DistributingEquivalentCategory<RigidArithmetic1d<T, n0> >,
  public DistributingMetricSpace<RigidArithmetic1d<T, n0>, double>,

  public ConcreteRigidArray1d<T, n0> {
public:
  RigidArithmetic1d() : ConcreteRigidArray1d<T, n0>() {}
  explicit RigidArithmetic1d(Subscript n) : ConcreteRigidArray1d<T, n0>(n) {}
  RigidArithmetic1d(const RigidArithmetic1d<T, n0>& a) : 
    ConcreteRigidArray1d<T, n0>(a) {}

  const RigidArithmetic1d<T, n0>& 
  operator=(const RigidArithmetic1d<T, n0>& rhs) {
    ConcreteRigidArray1d<T, n0>::operator=(rhs);
    return *this; }

  const RigidArithmetic1d<T, n0>& operator=(const T& rhs) {
    ConcreteRigidArray1d<T, n0>::operator=(rhs);
    return *this; }

  // c = a X b
  // Note that cross product makes sence only for vectors in 3D space.
  friend void crossProd<T>(const RigidArithmetic1d<T, 3>& a, 
			   const RigidArithmetic1d<T, 3>& b, 
			   RigidArithmetic1d<T, 3>& c);

  // CAD
  // moved to DistributingExternalScalars
  // lhs(i) = rhs(i) + s
  //friend void XplusScalar(RigidArithmetic1d& lhs, const RigidArithmetic1d& x, const T& s) {
  //  DistributeS<Add, RigidArithmetic1d, T>::over( lhs, x, s ); }

  // moved to DistributingExternalScalars
  // lhs(i) = rhs(i) * s
  //friend void XmultScalar(RigidArithmetic1d& lhs, const RigidArithmetic1d& x, const T& s) {
  //  DistributeS<Mult, RigidArithmetic1d, T>::over( lhs, x, s ); }

  // moved to DistributingAbelianSemiGroup
  // lhs = x + y
  //friend void XplusY(RigidArithmetic1d& lhs, 
  //	     const RigidArithmetic1d& x, const RigidArithmetic1d& y) {
  //  Distribute3<Add, RigidArithmetic1d>::over( lhs, x, y ); } 

  // moved to DistributingAbelianGroup
  // lhs = x - y
  //friend void XminusY(RigidArithmetic1d& lhs, 
  //	     const RigidArithmetic1d& x, const RigidArithmetic1d& y) {
  //  Distribute3<Sub, RigidArithmetic1d>::over( lhs, x, y ); } 

  // moved to DistributingSemiGroup
  // lhs(i) = x(i) * y(i)
  //friend void XtimesY(RigidArithmetic1d& lhs, 
  //	     const RigidArithmetic1d& x, const RigidArithmetic1d& y) {
  //  Distribute3<Mult, RigidArithmetic1d>::over( lhs, x, y ); } 

  // moved to DistributingGroup
  // lhs(i) = x(i) / y(i)
  //friend void XdivY(RigidArithmetic1d& lhs, 
  //	     const RigidArithmetic1d& x, const RigidArithmetic1d& y) {
  // Distribute3<Div, RigidArithmetic1d>::over( lhs, x, y ); } 

  // CAD
  /*
private:
  class Add  { public: Add (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 + rhs1; } };

  class Sub  { public: Sub (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 - rhs1; } };

  class Mult { public: Mult (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 * rhs1; } };

  class Div { public: Div (T& lhs, const T& rhs0, const T& rhs1) { lhs = rhs0 / rhs1; } };
  */
};



template<class T, Subscript n0, Subscript n1>
class RigidArithmetic2d :
  public DivisionAlgebraCategory< RigidArithmetic2d<T, n0, n1>, T >,

  public DistributingDivisionAlgebra< RigidArithmetic2d<T, n0, n1>, T, T>,
  public DistributingEquivalentCategory<RigidArithmetic2d<T, n0, n1> >,

  public ConcreteRigidArray2d<T, n0, n1> {
public:

  RigidArithmetic2d() :  ConcreteRigidArray2d<T, n0, n1>() {}
  
  RigidArithmetic2d(Subscript na, Subscript nb) :
    ConcreteRigidArray2d<T, n0, n1>(na, nb) {}

  RigidArithmetic2d(const RigidArithmetic2d<T, n0, n1>& a) : 
    ConcreteRigidArray2d<T, n0, n1>(a) {}  
      
  const RigidArithmetic2d<T, n0, n1>& 
  operator=(const RigidArithmetic2d<T, n0, n1>& rhs) {
    ConcreteRigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }

  const RigidArithmetic2d<T, n0, n1>& operator=(const T& rhs) {
    ConcreteRigidArray2d<T, n0, n1>::operator=(rhs);
    return *this;
  }
};

#ifdef XLC_QNOTEMPINC
#include "Vector/RigidArithmetic.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LapackArithmeticH
#define LapackArithmeticH

#include "LapackWrap/Lapack.h"
#include "Algebra/MetricSpaceCategory.h"
#include "Algebra/SemiGroupCategory.h"
#include "Vector/MatrixCategory.h"

template<class T,class Measure>
class ConstLapackVector :
  public ConstArrayProjection1d<T>,
  public MetricSpaceCategory<ConstLapackVector<T,Measure>,Measure> {
public:
  ConstLapackVector(const ConstArray2d<T>& a, Subscript i) : ConstArrayProjection1d<T>(a,i,1) {}
  
  Measure dot(const ConstLapackVector<T,Measure>& rhs) const;
};

template<class T,class Measure>
class LapackVector :
  public virtual Array1d<T>,
  public ConstLapackVector<T,Measure> {
public:
  LapackVector(Array2d<T>& a, Subscript i) : ConstLapackVector<T,Measure>(a,i) {}
  LapackVector<T,Measure>& operator=(const Array1d<T>& a){
    doAssign(a);
    return *this;
  }
  LapackVector<T,Measure>& operator=(const T& a){
    doAssign(a);
    return *this;
  }
};

#include "Vector/DistributingAbelianGroup.h"
                                                     
template<class Rep, class Measure>
class LapackArithmetic :
  public LapackUnfactored<Rep>,
  public DistributingAbelianGroup<LapackArithmetic<Rep,Measure>, LapackUnfactored<Rep>::EltT>,
  public SemiGroupCategory< LapackArithmetic<Rep,Measure> >,
  public MetricSpaceCategory< LapackArithmetic<Rep, Measure>, Measure > {
public:
  LapackArithmetic(Subscript nrows, Subscript ncols) : LapackUnfactored<Rep>(nrows,ncols){}
  LapackArithmetic(const ConstArray2d<EltT>& rhs) : LapackUnfactored<Rep>(rhs) {}
  
  LapackArithmetic<Rep, Measure>& operator=(const ConstArray2d<EltT>& rhs) {
    LapackUnfactored<Rep>::operator=(rhs);
    return *this;
    }
  LapackArithmetic<Rep, Measure>& operator=(const EltT& rhs) {
    LapackUnfactored<Rep>::operator=(rhs);
    return *this;
    }
   
   LapackArithmetic<Rep, Measure>& operator*=(const LapackArithmetic<Rep, Measure>& a){ rep() *= a.rep(); return *this; }
                 
   ConstLapackVector<EltT,Measure> operator[](Subscript i) const { return ConstLapackVector<EltT,Measure>(*this,i); }
   LapackVector<EltT,Measure> operator[](Subscript i) { return LapackVector<EltT,Measure>(*this,i); }
   
   Measure dot(const LapackArithmetic<Rep, Measure>& rhs) const;
};

#ifdef XLC_QNOTEMPINC
#include "AutoDeriv/LapackArithmetic.c"
#endif

#endif

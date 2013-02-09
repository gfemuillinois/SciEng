/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteBlas1dH
#define ConcreteBlas1dH

#include "Algebra/LinearSpaceCategory.h"
#include "Algebra/MetricSpaceCategory.h"

#include "Vector/DistributingLinearSpace.h"
#include "Vector/DistributingEquivalentCategory.h"

#include "SciEng/ArrayErr.h"
#include "Array/ConcreteFortranArray1d.h"
#include "Array/ConcreteFortranArray2d.h"
#include "LapackWrap/BlasSubroutines.h"


template<class T>
class ConcreteBlas1d :            
    public LinearSpaceCategory< ConcreteBlas1d<T>, T>,
    public MetricSpaceCategory< ConcreteBlas1d<T>, T>,
 
    public DistributingLinearSpace<ConcreteBlas1d<T>, T, T>,
    public DistributingEquivalentCategory<ConcreteBlas1d<T> >,

    public ConcreteFortranArray1d<T> {
public:
  explicit ConcreteBlas1d(Subscript n) : 
    ConcreteFortranArray1d<T>(n) {}
  ConcreteBlas1d(const ConcreteBlas1d<T>& a) : 
    ConcreteFortranArray1d<T>(a) {}
  ConcreteBlas1d(const typename ConcreteFortranArray2d<T>::ConstProjectionT& a) :
    ConcreteFortranArray1d<T>(a) {}
  ConcreteBlas1d(const typename ConcreteFortranArray2d<T>::ProjectionT& a) :
    ConcreteFortranArray1d<T>(a) {}

  using ConcreteFortranArray1d<T>::numElts;
  using ConcreteFortranArray1d<T>::firstDatum;

  // User must define function for MetricSpaceCategory
  T dot(const ConcreteBlas1d<T>& rhs) const {
    //  cout << "ConcreteBlas1d<T>::dot" << endl;

    if( numElts() != rhs.numElts() ) throw ArrayErr::Shape();
    return Blas1Subroutines::xdot( int(numElts()), firstDatum(), 1, 
				   rhs.firstDatum(), 1);
  }

  const ConcreteBlas1d<T>& operator=(const ConcreteBlas1d<T>& rhs) {
    ConcreteFortranArray1d<T>::operator=(rhs);
    return *this;
  }

  const ConcreteBlas1d<T>& operator=(const T& rhs) {
    ConcreteFortranArray1d<T>::operator=(rhs);
    return *this;
  }
};



#endif

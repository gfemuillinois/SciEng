/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteBlas2dH
#define ConcreteBlas2dH

#include "Array/ConcreteFortranArray2d.h"

#include "Algebra/AlgebraWithUnitCategory.h"

#include "Vector/DistributingAbelianGroup.h"
#include "Vector/DistributingLinearSpace.h"
#include "Vector/DistributingEquivalentCategory.h"

#include "LapackWrap/ConcreteBlas1d.h"

template<class T> class ConstConcreteBlasProjection1d;

template<class T>
ConcreteBlas1d<T> 
operator*(const T& lhs, const ConstConcreteBlasProjection1d<T>& rhs);

template<class T>
ConcreteBlas1d<T> 
operator*(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs);

template<class T>
ConcreteBlas1d<T> 
operator/(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs);

#undef  PROTECT_COPY_CONSTRUCTOR
#define PROTECT_COPY_CONSTRUCTOR 1
#if PROTECT_COPY_CONSTRUCTOR
template<class T> class ConcreteBlas2d;
template<class Rep> class LapackUnfactored;
#endif

template<class T>
class ConstConcreteBlasProjection1d :  
    public ConcreteFortranArray2d<T>::ConstProjectionT {
public:
  ConstConcreteBlasProjection1d(const typename 
				ConcreteFortranArray2d<T>::ConstProjectionT&
				underlying_proj) :
    ConcreteFortranArray2d<T>::ConstProjectionT(underlying_proj) {}

  ConstConcreteBlasProjection1d( typename 
				 ConcreteFortranArray2d<T>::ConstProjectionT::SubscriptorT
				 s, const T* p) :
    ConcreteFortranArray2d<T>::ConstProjectionT(s, p) {}

  friend ConcreteBlas1d<T> 
  operator*<T>(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs);

  friend ConcreteBlas1d<T> 
  operator*<T>(const T& lhs, const ConstConcreteBlasProjection1d<T>& rhs);

  friend ConcreteBlas1d<T> 
  operator/<T>(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs);

  double dot(const ConstConcreteBlasProjection1d<T>& rhs) const;

#if PROTECT_COPY_CONSTRUCTOR
  friend class ConcreteBlas2d< T >;
  //  template<class Rep> friend class LapackUnfactored;  
private:
  // Copying a projection would just copy the reference to the underlying array,
  // not the elements.  To avoid confusion, we prohibit copying.
#endif
  // The default copy constructor is being used: Just call the one from base class
  ConstConcreteBlasProjection1d(const ConstConcreteBlasProjection1d<T>&);  
};

template<class T>
inline
ConcreteBlas1d<T> 
operator*(const T& lhs, const ConstConcreteBlasProjection1d<T>& rhs) 
{ return rhs * lhs; }


template<class T> class ConcreteBlasProjection1d;

template<class T> 
ConcreteBlas1d<T> operator*(const ConcreteBlasProjection1d<T>& lhs, const T& rhs);
template<class T> 
ConcreteBlas1d<T> operator*(const T& lhs, const ConcreteBlasProjection1d<T>& rhs);
template<class T> 
ConcreteBlas1d<T> operator/(const ConcreteBlasProjection1d<T>& lhs, const T& rhs);


template<class T>
class ConcreteBlasProjection1d :  
    public ConcreteFortranArray2d<T>::ProjectionT {
public:
  typedef typename ConcreteFortranArray2d<T>::ProjectionT BaseType;

  ConcreteBlasProjection1d(const typename 
			   ConcreteFortranArray2d<T>::ProjectionT& underlying_proj) :
    ConcreteFortranArray2d<T>::ProjectionT(underlying_proj) {}

  ConcreteBlasProjection1d(typename 
			   ConcreteFortranArray2d<T>::ProjectionT::SubscriptorT s, T* p) :
    ConcreteFortranArray2d<T>::ProjectionT(s, p) {}

  ConcreteBlasProjection1d<T>& 
  operator=( const ConcreteArray1dConstRef<typename 
	     ConcreteFortranArray2d<T>::ProjectionT::ProjectionSubscriptor, T> rhs);

  ConcreteBlasProjection1d<T>& 
  operator=(const typename ConcreteFortranArray2d<T>::ConstProjectionT& rhs);

  ConcreteBlasProjection1d<T>& operator=(const T& rhs);

  double dot(const ConcreteBlasProjection1d<T>& rhs) const;

  ConcreteBlasProjection1d<T>& operator*=(const T& rhs);

  friend ConcreteBlas1d<T> 
  operator*<T>(const ConcreteBlasProjection1d<T>& lhs, const T& rhs);

  friend ConcreteBlas1d<T> 
  operator*<T>(const T& lhs, const ConcreteBlasProjection1d<T>& rhs);

  ConcreteBlasProjection1d<T>& operator/=(const T& rhs);

  friend ConcreteBlas1d<T> 
  operator/<T>(const ConcreteBlasProjection1d<T>& lhs, const T& rhs);

  operator ConstConcreteBlasProjection1d<T>() {
    return ConcreteFortranArray2d<T>::ConstProjectionT(*this);
  }

#if PROTECT_COPY_CONSTRUCTOR
  // cad: These classes need access to the copy constructor
  friend class ConcreteBlas2d< T >;

private:
  // Copying a projection would just copy the reference to the underlying array,
  // not the elements.  To avoid confusion, we prohibit copying.
#endif
  // The default copy constructor is being used: Just call the one from base class
  ConcreteBlasProjection1d(const ConcreteBlasProjection1d<T>&);  
};


template<class T>
inline
ConcreteBlasProjection1d<T>& ConcreteBlasProjection1d<T>::
operator=(const ConcreteArray1dConstRef< 
	  typename ConcreteFortranArray2d<T>::ProjectionT::ProjectionSubscriptor, T> rhs) 
{     
  (typename ConcreteFortranArray2d<T>::ProjectionT)::operator=(rhs);
  return *this;
}

template<class T>
inline
ConcreteBlasProjection1d<T>& ConcreteBlasProjection1d<T>::
operator=(const typename ConcreteFortranArray2d<T>::ConstProjectionT& rhs) 
{ 
  (typename ConcreteFortranArray2d<T>::ProjectionT)::operator=(rhs);
  return *this;
}

template<class T>
inline
ConcreteBlasProjection1d<T>& ConcreteBlasProjection1d<T>::operator=(const T& rhs) { 
  //  (typename ConcreteFortranArray2d<T>::ProjectionT)::operator=(rhs);
  BaseType::operator=(rhs);
  return *this;
}

template<class T>
inline
ConcreteBlas1d<T> operator*(const T& lhs, const ConcreteBlasProjection1d<T>& rhs) 
{ return rhs * lhs; }



template<class T> class ConcreteBlas2d;

template<class T>
ConcreteBlas1d<T> operator*(const ConcreteBlas2d<T>& m, const ConcreteBlas1d<T>& v);

template<class T>
void mult(const ConcreteBlas2d<T>& A, const ConcreteBlas1d<T>& b,
	  ConcreteBlas1d<T>& c);

template<class T>
void mult( const ConcreteBlas2d<T>& A, const ConcreteBlas2d<T>& B,
	   ConcreteBlas2d<T>& C);


template<class T>
class ConcreteBlas2d :               
  public AlgebraWithUnitCategory<ConcreteBlas2d<T>, T>,

  // CAD
  //  public DistributingAbelianGroup<ConcreteBlas2d<T>, T>,
  public DistributingLinearSpace<ConcreteBlas2d<T>, T, T>,
  public DistributingEquivalentCategory<ConcreteBlas2d<T> >,

  public ConcreteFortranArray2d<T> {
public:
  ConcreteBlas2d(const ConcreteFortranArray2d<T>& a);
  ConcreteBlas2d(Subscript nrows, Subscript ncols);


  typedef ConstConcreteBlasProjection1d<T> ConstProjectionT;
  typedef      ConcreteBlasProjection1d<T>      ProjectionT;

  // CAD
  // AlgebraWithUnitCategory ops not implemented by DistributingLinearSpace.
  ConcreteBlas2d<T>& operator*=(const ConcreteBlas2d<T>& rhs);
  ConcreteBlas2d<T>& setToOne();
  // overwriting the one defined in DistributingExternalScalars
  ConcreteBlas2d<T>& operator*=(const T& rhs);
  // overwriting the one defined in DistributingFieldScalars
  ConcreteBlas2d<T>& operator/=(const T& rhs);

  
  ConcreteBlas2d<T>& operator=(const ConcreteBlas2d<T>& rhs);
  ConcreteBlas2d<T>& operator=(const T& rhs);


  ConstProjectionT project(Subscript i, Dimension d = 0) const;
  ProjectionT project(Subscript i, Dimension d = 0);

  ConstProjectionT operator[](Subscript i) const { return project(i, 0); }
  ProjectionT operator[](Subscript i)       { return project(i, 0); }

  ConstProjectionT row(Subscript i)    const { return project(i, 0); }
  ProjectionT row(Subscript i)          { return project(i, 0); }
  ConstProjectionT column(Subscript i) const { return project(i, 1); }
  ProjectionT column(Subscript i)       { return project(i, 1); }


  // Matrix-Vector (Blas Level 2) Operation
  friend ConcreteBlas1d<T> 
  operator*<T>(const ConcreteBlas2d<T>& m, const ConcreteBlas1d<T>& v);

  // same as above: c = A * b
  friend void mult<T>(const ConcreteBlas2d<T>& A, const ConcreteBlas1d<T>& b,
		      ConcreteBlas1d<T>& c);

  // To be used instead of operator* from SemiGroupCategory
  // C = A * B
  friend void mult<T>( const ConcreteBlas2d<T>& A, const ConcreteBlas2d<T>& B,
		       ConcreteBlas2d<T>& C);

};


template<class T>
inline
ConcreteBlas2d<T>::ConcreteBlas2d(const ConcreteFortranArray2d<T>& a) :
  ConcreteFortranArray2d<T>(a) {}

template<class T>
inline
ConcreteBlas2d<T>::ConcreteBlas2d(Subscript nrows, Subscript ncols) :
  ConcreteFortranArray2d<T>(nrows, ncols) {}


template<class T>
inline
ConcreteBlas2d<T>& ConcreteBlas2d<T>::operator=(const ConcreteBlas2d<T>& rhs){ 
  ConcreteFortranArray2d<T>::operator=(rhs);
  return *this;
}


template<class T>
inline
ConcreteBlas2d<T>& ConcreteBlas2d<T>::operator=(const T& rhs){ 
  ConcreteFortranArray2d<T>::operator=(rhs);
  return *this;
}

template<class T>
ostream& operator<<(ostream& os, const ConstConcreteBlasProjection1d<T>& p);

#ifdef XLC_QNOTEMPINC
#include "LapackWrap/ConcreteBlas2d.c"
#endif

#endif

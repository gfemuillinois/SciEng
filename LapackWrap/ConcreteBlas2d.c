/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "LapackWrap/BlasSubroutines.h"


template<class T>
ConcreteBlas2d<T>& ConcreteBlas2d<T>::operator*=(const T& rhs) {
    Blas3Subroutines::xscal(numElts(), rhs, firstDatum(), 1);
    return *this;
}

template<class T>
ConcreteBlas1d<T> operator*(const ConcreteBlas2d<T>& m, const ConcreteBlas1d<T>& v) {
    ConcreteBlas1d<T> result( m.shape(0) );

    Blas3Subroutines::xgemv(
        Blas3Subroutines::no_trans,
        m.shape(0), m.shape(1),
        T(1), m.firstDatum(), m.shape(0), 
        v.firstDatum(), 1,
        T(0), result.firstDatum(), 1
        );

    return result;
}


template<class T>
ConcreteBlas2d<T>& ConcreteBlas2d<T>::operator/=(const T& rhs) {
    Blas3Subroutines::xscal(numElts(), T(1) / rhs, firstDatum(), 1);
    return *this;
}


template<class T>
ConcreteBlas2d<T>& ConcreteBlas2d<T>::operator*=(const ConcreteBlas2d<T>& rhs) { 
    ConcreteBlas2d<T> lhs(*this);  // Copy out left operand
    reshape(SubscriptArray<2>(shape(0), rhs.shape(1)));  // Make room for product
    Blas3Subroutines::xgemm( 
        Blas3Subroutines::no_trans, Blas3Subroutines::no_trans, 
        lhs.shape(0), rhs.shape(1), rhs.shape(0),
        T(1), lhs.firstDatum(), lhs.shape(0),
        rhs.firstDatum(), rhs.shape(0),
        T(0), firstDatum(), shape(0)
    );
    return *this;
}


template<class T>
ConcreteBlas2d<T>& ConcreteBlas2d<T>::setToOne() {
  *this = T(0);
  Subscript i = shape(0);
  T one(1);
  while (i-- > 0) (*this)(i, i) = one;
  return *this;
}

template<class T>
ConcreteBlasProjection1d<T>& ConcreteBlasProjection1d<T>::operator*=(const T& rhs) {
  for (typename ConcreteFortranArray2d<T>::ProjectionT::IteratorType i(*this); i.more(); i.advance()) {
    i.current() *= rhs;
  }
  return *this;
}

template<class T>
ConcreteBlasProjection1d<T>& ConcreteBlasProjection1d<T>::operator/=(const T& rhs) {
  for (typename ConcreteFortranArray2d<T>::ProjectionT::IteratorType i(*this); i.more(); i.advance()) {
    i.current() /= rhs;
  }
  return *this;
}

template<class T>
double ConcreteBlasProjection1d<T>::dot(const ConcreteBlasProjection1d<T>& rhs) const {
   if ( shape(0) != rhs.shape(0) ) throw ArrayErr::Shape();
   return Blas1Subroutines::xdot(shape(0), firstDatum(), offset(1), rhs.firstDatum(), rhs.offset(1));
}

template<class T>
ConcreteBlas1d<T> operator*(const ConcreteBlasProjection1d<T>& lhs, const T& rhs) {
  ConcreteBlas1d<T> result(lhs);
  return result *= rhs;
}

template<class T>
ConcreteBlas1d<T> operator/(const ConcreteBlasProjection1d<T>& lhs, const T& rhs) {
  ConcreteBlas1d<T> result(lhs);
  return result /= rhs;
}

template<class T>
ostream& operator<<(ostream& os, const ConstConcreteBlasProjection1d<T>& p) {
  ConcreteArray1dConstRef< typename ConcreteBlas2d<T>::ConstProjectionT::SubscriptorT, T> pr = p;
  return os << pr;
}


template<class T>
double 
ConstConcreteBlasProjection1d<T>::dot(const ConstConcreteBlasProjection1d<T>& rhs) const {
    if ( shape(0) != rhs.shape(0) ) throw ArrayErr::Shape();
    return Blas1Subroutines::xdot(shape(0), firstDatum(), offset(1), rhs.firstDatum(), rhs.offset(1));
}



template<class T>
ConcreteBlas1d<T> operator*(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs) {
    ConcreteBlas1d<T> result(lhs);
    return result *= rhs;
}


template<class T>
ConcreteBlas1d<T> operator/(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs) {
  ConcreteBlas1d<T> result(lhs);
  return result /= rhs;
}


template<class T>
typename ConcreteBlas2d<T>::ConstProjectionT
ConcreteBlas2d<T>::project(Subscript i, Dimension d) const {
    return ConcreteFortranArray2d<T>::project(i, d);
}


template<class T>
typename ConcreteBlas2d<T>::ProjectionT 
ConcreteBlas2d<T>::project(Subscript i, Dimension d) {
  return ConcreteFortranArray2d<T>::project(i, d);
}


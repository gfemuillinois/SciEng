/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/arrayCopy.h"
template<class StridedArray2d>
ColumnNorms<StridedArray2d>::ColumnNorms(const Array1d<T>& m) :
  FormedArithmetic1d<T>(m.numElts()){
  arrayCopy(*this, m);
}


template<class StridedArray2d>
ColumnNorms<StridedArray2d>::ColumnNorms(const StridedArray2d& a) : 
    FormedArithmetic1d<T>(a.shape(1)) {
    const SubscriptArray<1> lda(1);  // stride between col elements is offset along col.
    for (int j = 0; j < a.shape(1); j++) { 
        StridedArray2d::ConstProjectionT col = a.column(j);
        (*this)[j] = 
            Blas1Subroutines::xnrm2(col.shape(0), col.firstDatum(), col.offset(lda));
    }
}


#include "SciEng/NumericalLimits.h"


template<class StridedArray2d>
StridedArray2d& ColumnNorms<StridedArray2d>::normalize(StridedArray2d& m){ 
    if (m.shape(1) != shape(0)) throw ArrayErr::Shape();

    const SubscriptArray<1> lda(1);  // stride between col elements is offset along col.
    for (Subscript j = 0; j < m.shape(1); j++) {
    StridedArray2d::ProjectionT col = m.column(j);
    T scale = (*this)(j);
    scale = scale > NumericalLimits<T>::epsilon ? (1.0 / scale) : T(0);
    Blas1Subroutines::xscal(col.shape(0), scale, col.firstDatum(), col.offset(lda));
    }
    return m;
}


template<class Subscriptor, class T, class StridedArray2d>
void normalize(ConcreteArray1dRef<Subscriptor,T> v, const ColumnNorms<StridedArray2d>& norms){
  Subscript n = v.shape(0);
  for (Subscript j = 0; j < n; j++) {
    v(j) /= norms(j);
  }
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ColumnNormsH
#define ColumnNormsH

#include "Vector/FormedArithmetic.h"


template<class StridedArray2d>
class ColumnNorms :  
    public FormedArithmetic1d<StridedArray2d::EltT> {
public:
    typedef StridedArray2d::EltT T;

    ColumnNorms(const StridedArray2d& m);   // Compute norms of these columns.
    ColumnNorms(const Array1d<T>& m);       // Copy these as norms.

    ColumnNorms() : FormedArithmetic1d<T>(1) {}
    ColumnNorms(const ColumnNorms<StridedArray2d>& c) : FormedArithmetic1d<T>(c) {}
    ColumnNorms<StridedArray2d>& operator=(const ColumnNorms<StridedArray2d>& c) {
    FormedArithmetic1d<T>::operator=(c);
    return *this;
    }
    StridedArray2d& normalize(StridedArray2d& m);
};


template<class Subscriptor, class T, class StridedArray2d>
void normalize( ConcreteArray1dRef<Subscriptor,T> a, const ColumnNorms<StridedArray2d>& norms );

#include "LapackWrap/ConcreteBlas1d.h"
template<class T, class StridedArray2d>
inline void normalize(ConcreteFortranArray1d<T>& a, const ColumnNorms<StridedArray2d>& norms) {
   ConcreteArray1dRef<ConcreteFortranArray1d<T>::SubscriptorT,T> ar = a;
   normalize(ar, norms);
}
#include "LapackWrap/ConcreteBlas2d.h"
template<class T, class StridedArray2d>
inline void normalize(const ConcreteFortranArray2d<T>::ProjectionT& a, const ColumnNorms<StridedArray2d>& norms) {
   ConcreteArray1dRef<ConcreteFortranArray2d<T>::ProjectionT::SubscriptorT,T> ar = a;
   normalize(ar, norms);
}

#ifdef XLC_QNOTEMPINC
#include "LapackWrap/ColumnNorms.c"
#endif

#endif

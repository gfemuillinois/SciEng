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

#include "Algebra/LinearSpaceCategory.h"
#include "Algebra/MetricSpaceCategory.h"
#include "Vector/DistributingLinearSpace.h"


#include "Algebra/AlgebraWithUnitCategory.h"
#include "Vector/DistributingAbelianGroup.h"
#include "LapackWrap/ConcreteBlas1d.h"


template<class T>
class ConstConcreteBlasProjection1d :  
    public ConcreteFortranArray2d<T>::ConstProjectionT {
public:
    ConstConcreteBlasProjection1d(const ConcreteFortranArray2d<T>::ConstProjectionT& underlying_proj) :
        ConcreteFortranArray2d<T>::ConstProjectionT(underlying_proj) {}
    ConstConcreteBlasProjection1d(ConcreteFortranArray2d<T>::ConstProjectionT::SubscriptorT s, const T* p) :
        ConcreteFortranArray2d<T>::ConstProjectionT(s, p) {}

    friend ConcreteBlas1d<T> operator*(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs);
    friend ConcreteBlas1d<T> operator*(const T& lhs, const ConstConcreteBlasProjection1d<T>& rhs);
    friend ConcreteBlas1d<T> operator/(const ConstConcreteBlasProjection1d<T>& lhs, const T& rhs);

    double dot(const ConstConcreteBlasProjection1d<T>& rhs) const;
private:
    // Copying a projection would just copy the reference to the underlying array,
    // not the elements.  To avoid confusion, we prohibit copying.
    ConstConcreteBlasProjection1d(const ConstConcreteBlasProjection1d<T>&);  
};


template<class T>
inline
ConcreteBlas1d<T> operator*(const T& lhs, const ConstConcreteBlasProjection1d<T>& rhs) { return rhs * lhs; }

template<class T>
class ConcreteBlasProjection1d :  
    public ConcreteFortranArray2d<T>::ProjectionT {
public:
    ConcreteBlasProjection1d(const ConcreteFortranArray2d<T>::ProjectionT& underlying_proj) :
        ConcreteFortranArray2d<T>::ProjectionT(underlying_proj) {}
    ConcreteBlasProjection1d(ConcreteFortranArray2d<T>::ProjectionT::SubscriptorT s, T* p) :
        ConcreteFortranArray2d<T>::ProjectionT(s, p) {}

    ConcreteBlasProjection1d<T>& operator=(const ConcreteArray1dConstRef<ProjectionSubscriptor, T> rhs);
    ConcreteBlasProjection1d<T>& operator=(const ConcreteFortranArray2d<T>::ConstProjectionT& rhs);
    ConcreteBlasProjection1d<T>& operator=(const T& rhs);

    double dot(const ConcreteBlasProjection1d<T>& rhs) const;
    ConcreteBlasProjection1d<T>& operator*=(const T& rhs);
    friend ConcreteBlas1d<T> operator*(const ConcreteBlasProjection1d<T>& lhs, const T& rhs);
    friend ConcreteBlas1d<T> operator*(const T& lhs, const ConcreteBlasProjection1d<T>& rhs);
    ConcreteBlasProjection1d<T>& operator/=(const T& rhs);
    friend ConcreteBlas1d<T> operator/(const ConcreteBlasProjection1d<T>& lhs, const T& rhs);

    operator ConstConcreteBlasProjection1d<T>() {
        return ConcreteFortranArray2d<T>::ConstProjectionT(*this);
    }
    private:
    // Copying a projection would just copy the reference to the underlying array,
    // not the elements.  To avoid confusion, we prohibit copying.
    ConcreteBlasProjection1d(const ConcreteBlasProjection1d<T>&);  
};

template<class T>
inline
ConcreteBlasProjection1d<T>& 
ConcreteBlasProjection1d<T>::operator=(const ConcreteArray1dConstRef<ProjectionSubscriptor, T> rhs) {     
    ConcreteFortranArray2d<T>::ProjectionT::operator=(rhs);
    return *this;
}
  
template<class T>
inline
ConcreteBlasProjection1d<T>& 
ConcreteBlasProjection1d<T>::operator=(const ConcreteFortranArray2d<T>::ConstProjectionT& rhs) { 
    ConcreteFortranArray2d<T>::ProjectionT::operator=(rhs);
    return *this;
}

template<class T>
inline
ConcreteBlasProjection1d<T>& ConcreteBlasProjection1d<T>::operator=(const T& rhs) { 
    ConcreteFortranArray2d<T>::ProjectionT::operator=(rhs);
    return *this;
}

template<class T>
inline
ConcreteBlas1d<T> operator*(const T& lhs, const ConcreteBlasProjection1d<T>& rhs) { return rhs * lhs; }


template<class T>
class ConcreteBlas2d :               
    public AlgebraWithUnitCategory<ConcreteBlas2d<T>, T>,
    public DistributingAbelianGroup<ConcreteBlas2d<T>, T>,
    public ConcreteFortranArray2d<T> {
public:
    ConcreteBlas2d(const ConcreteFortranArray2d<T>& a);
    ConcreteBlas2d(Subscript nrows, Subscript ncols);


    typedef ConstConcreteBlasProjection1d<T> ConstProjectionT;
    typedef      ConcreteBlasProjection1d<T>      ProjectionT;


    // AlgebraWithUnitCategory ops not implemented by DistributingAbelianGroup.
    ConcreteBlas2d<T>& operator*=(const T& rhs);
    ConcreteBlas2d<T>& operator*=(const ConcreteBlas2d<T>& rhs);
    ConcreteBlas2d<T>& operator/=(const T& rhs);
    ConcreteBlas2d<T>& setToOne();

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
    friend ConcreteBlas1d<T> operator*(const ConcreteBlas2d<T>& m, const ConcreteBlas1d<T>& v);
};


template<class T>
inline
ConcreteBlas2d<T>::ConcreteBlas2d(const ConcreteFortranArray2d<T>& a) : ConcreteFortranArray2d<T>(a) {}

template<class T>
inline
ConcreteBlas2d<T>::ConcreteBlas2d(Subscript nrows, Subscript ncols) : ConcreteFortranArray2d<T>(nrows, ncols) {}


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

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef TransposedConcreteBlas2dH
#define TransposedConcreteBlas2dH

#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArray2d.h"
#include "LapackWrap/ConcreteBlas2d.h"
#include "SciEng/Boolean.h"


template<class T>
class TransposedConcreteBlas2d :               
    public ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, T> {
public:
    TransposedConcreteBlas2d(ConcreteBlas2d<T>& a);


    friend ConcreteBlas2d<T> operator*(const TransposedConcreteBlas2d<T>& t, const TransposedConcreteBlas2d<T>& u);
    friend ConcreteBlas2d<T> operator*(const ConcreteBlas2d<T>& u,           const TransposedConcreteBlas2d<T>& t);
    friend ConcreteBlas2d<T> operator*(const TransposedConcreteBlas2d<T>& t, const ConcreteBlas2d<T>& u);
    friend ConcreteBlas1d<T> operator*(const TransposedConcreteBlas2d<T>& t, const ConcreteBlas1d<T>& u);


    operator ConcreteBlas2d<T>() const;
};


template<class T>
inline
ostream& operator<<(ostream& os, const TransposedConcreteBlas2d<T>& a) {
  return os << ConcreteArray2dConstRef<TransposedConcreteBlas2d<T>::SubscriptorT, T>(a);
}

#ifdef XLC_QNOTEMPINC
#include "LapackWrap/TransposedConcreteBlas2d.c"
#endif
      
#endif

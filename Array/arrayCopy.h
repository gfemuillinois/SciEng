/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef arrayCopyH
#define arrayCopyH

#include "Array/Array1d.h"
#include "Array/ConcreteArray1d.h"
#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFortranArray1d.h"
#include "LapackWrap/ConcreteBlas1d.h"

// Always put the most specific type on the lhs to avoid ambiguious templates.

template<class AnArray, class T>
void arrayCopy(Array1d<T>& lhs, const AnArray& rhs);

/*
template<class AnArray, class T>
void arrayCopy(AnArray& lhs, const ConstArray1d<T>& rhs);
*/

template<class Subscriptor, class T>
void arrayCopy(const ConcreteArray1dRef<Subscriptor, T>& lhs, const ConstArray1d<T>& rhs);

template<class T>
inline void arrayCopy(ConcreteFormedArray1d<T>& lhs, const ConstArray1d<T>& rhs) {
  ConcreteArray1dRef< ConcreteFormedArray1d<T>::SubscriptorT, T > _lhs(lhs);
  arrayCopy(_lhs, rhs);
}

template<class T>
inline void arrayCopy(ConcreteFortranArray1d<T>& lhs, const ConstArray1d<T>& rhs) {
  ConcreteArray1dRef< ConcreteFortranArray1d<T>::SubscriptorT, T > _lhs(lhs);
  arrayCopy(_lhs, rhs);
}

template<class T>
inline void arrayCopy(ConcreteBlas1d<T>& lhs, const ConstArray1d<T>& rhs) {
  ConcreteArray1dRef< ConcreteBlas1d<T>::SubscriptorT, T > _lhs(lhs);
  arrayCopy(_lhs, rhs);
}

#ifdef XLC_QNOTEMPINC
#include "Array/arrayCopy.c"
#endif

#endif

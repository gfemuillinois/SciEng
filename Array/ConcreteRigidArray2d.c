/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayTuplize.h"

template<class T, Subscript n0, Subscript n1>
ConstConcreteArrayProjection1d<ConcreteRigidArray2d<T, n0, n1>::SubscriptorT, T>
ConcreteRigidArray2d<T, n0, n1>::project(Subscript s, Dimension d)  const {
   SubscriptArray<2> pjs(0,0);
   pjs(d) = s;
   SubscriptorT the_subscriptor(SubscriptArray<2>(n0, n1));
   return ConstConcreteArrayProjection1d< SubscriptorT, T >(
     the_subscriptor.projectionSubscriptor(d, s),
     firstDatum()+offset(pjs)
  );
}

template<class T, Subscript n0, Subscript n1>
ConcreteArrayProjection1d<ConcreteRigidArray2d<T, n0, n1>::SubscriptorT, T>
ConcreteRigidArray2d<T, n0, n1>::project(Subscript s, Dimension d)  {
   SubscriptArray<2> pjs(0,0);
   pjs(d) = s;
   SubscriptorT the_subscriptor(SubscriptArray<2>(n0, n1));
   return ConcreteArrayProjection1d< SubscriptorT, T >(
     the_subscriptor.projectionSubscriptor(d, s),
     firstDatum()+offset(pjs)
  );
}

template<class T, Subscript n0, Subscript n1>
ConcreteRigidArray2d<T, n0, n1>& ConcreteRigidArray2d<T, n0, n1>::operator=(const T& rhs) {
  T* p = firstDatum();
  T* const endp = p + numElts();
  while (p < endp) *p++ = rhs;
  return *this;
}

template<class T, Subscript n0, Subscript n1>
ConcreteRigidArray2d<T, n0, n1>& 
ConcreteRigidArray2d<T, n0, n1>::operator=(const ConcreteRigidArray2d<T, n0, n1>& rhs) {
  T* p = firstDatum();
  T* const endp = p + numElts();
  const T* p_rhs = rhs.firstDatum();
  const T* const endp_rhs = p_rhs + rhs.numElts();

  while (p < endp) *p++ = *p_rhs++;
  return *this;
}


template<class T, Subscript n0, Subscript n1>
ostream& operator<<(ostream& os, const ConcreteRigidArray2d<T, n0, n1>& a) {
  return arrayTuplize(a, os);
}

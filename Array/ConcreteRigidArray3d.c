/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayTuplize.h"

template<class T, Subscript n0, Subscript n1, Subscript n2>
ConcreteRigidArray3d<T, n0, n1, n2>::ConcreteRigidArray3d(Subscript s0, Subscript s1, Subscript s2) {
  if (s0 != n0 || s1 != n1 || s2 != n2) throw ArrayErr::CreationSize();
}

template<class T, Subscript n0, Subscript n1, Subscript n2>
ConcreteRigidArray3d<T, n0, n1, n2>& ConcreteRigidArray3d<T, n0, n1, n2>::operator=(const T& rhs) {
  T* p = firstDatum();
  T* const endp = p + numElts();
  while (p < endp) *p++ = rhs;
  return *this;
}
 
template<class T, Subscript n0, Subscript n1, Subscript n2>
ConstConcreteArrayProjection2d<typename ConcreteRigidArray3d<T, n0, n1, n2>::Subscriptor, T>
ConcreteRigidArray3d<T, n0, n1, n2>::project(Subscript s, Dimension d) const {
  SubscriptArray<3> pjs(0,0,0);
  pjs(d) = s;
  Subscriptor the_subscriptor(SubscriptArray<3>(n0, n1, n2));
  return ConstConcreteArrayProjection2d<Subscriptor, T>(
    the_subscriptor.projectionSubscriptor(d, s),
    firstDatum()+offset(pjs)
  );
}

template<class T, Subscript n0, Subscript n1, Subscript n2>
ConcreteArrayProjection2d<typename ConcreteRigidArray3d<T, n0, n1, n2>::Subscriptor, T>
ConcreteRigidArray3d<T, n0, n1, n2>::project(Subscript s, Dimension d) {
  SubscriptArray<3> pjs(0,0,0);
  pjs(d) = s;
  Subscriptor the_subscriptor(SubscriptArray<3>(n0, n1, n2));
  return ConcreteArrayProjection2d<Subscriptor, T>(
    the_subscriptor.projectionSubscriptor(d, s),
    firstDatum()+offset(pjs)
  );
}

template<class T, Subscript n0, Subscript n1, Subscript n2>
std::ostream& 
operator<<(std::ostream& os, const ConcreteRigidArray3d<T, n0, n1, n2>& a) {
  return arrayTuplize(a, os);
}

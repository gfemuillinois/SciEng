/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayTuplize.h"
#include "SciEng/ArrayErr.h"

template<class Subscriptor, class T>
ostream& operator<<(ostream& os, const ConcreteArray3dConstRef<Subscriptor, T>& a) {
  return arrayTuplize(a, os);
}

template<class Subscriptor, class T>
istream& operator>>(istream& is, const ConcreteArray3dRef<Subscriptor, T>& a) {
  char c = 0;
  is >> c;
  if (c == '[') {
      Subscript n = a.shape(0);
      int i = 0;
      while ( i < n ) {
        typename ConcreteArray3dRef<Subscriptor, T>::ProjectionT a_i = a[i];
	is >> a_i;
	if (!is.good()) break;
	is >> c;
	i++;
	if ( i == n ) {
	  if (c != ']') is.clear(std::ios::badbit);
	} else {
	  if (c != ',') is.putback(c);
	}
      }
  }
  else {
    is.putback(c);
    is.clear(std::ios::badbit);
  }
  return is;
}

template<class Subscriptor, class T>
ConstConcreteArrayProjection2d< Subscriptor, T >
ConcreteArray3dConstRef<Subscriptor, T>::project(Subscript s, Dimension d) const {
   SubscriptArray<3> pjs(0,0,0);
   pjs(d) = s;
   return ConstConcreteArrayProjection2d< Subscriptor, T >(
     projectionSubscriptor(d, s),
     firstDatum()+offset(pjs)
  );
}

template<class Subscriptor, class T>
ConcreteArrayProjection2d< Subscriptor, T >
ConcreteArray3dRef<Subscriptor, T>::project(Subscript s, Dimension d) const {
   SubscriptArray<3> pjs(0,0,0);
   pjs(d) = s;
   return ConcreteArrayProjection2d< Subscriptor, T >(
     projectionSubscriptor(d, s),
     firstDatum()+offset(pjs)
  );
}

template<class Subscriptor, class T>
void ConcreteArray3d<Subscriptor, T>::setSizeOnHeap(Subscript n) {
  delete[] datap;
  datap = new T[n];
}

template<class Subscriptor, class T>
ConcreteArray3dRef<Subscriptor, T>& ConcreteArray3dRef<Subscriptor, T>::operator=(const T& rhs) {
  Subscript n = shape(0);
  while (n-- > 0) (*this)[n] = rhs;
  return *this;
}

template<class ArrayShape, class AnotherShape, class T>
void concreteCopy(const ConcreteArray3dRef<ArrayShape, T>& lhs, const ConcreteArray3dConstRef<AnotherShape, T>& rhs) {
  Subscript n = lhs.shape(0);
  if (n != rhs.shape(0)) throw ArrayErr::Shape();
  while (n-- > 0) concreteCopy(lhs[n], rhs[n]);
}

template<class Subscriptor, class T>
ConcreteArray3dRef<Subscriptor, T>& 
ConcreteArray3dRef<Subscriptor, T>::operator=(const ConcreteArray3dConstRef<Subscriptor, T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class Subscriptor, class T>
void ConcreteArray3d<Subscriptor, T>::reshapeOnHeap(const SubscriptArray<3>& s) {
  setShape(s);
  setSizeOnHeap(numElts());
}

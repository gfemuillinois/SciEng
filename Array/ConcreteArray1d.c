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
ostream& operator<<(ostream& os, const ConcreteArray1dConstRef<Subscriptor, T>& a) {
  return arrayTuplize(a, os);
}

template<class Subscriptor, class T>
istream& operator>>(istream& is, ConcreteArray1dRef<Subscriptor, T> a) {
  char c = 0;
  is >> c;
  if (c == '[') {
      Subscript n = a.shape(0);
      Subscript i = 0;
      while (i < n) {
	is >> a(i);
	if (!is.good()) break;
	is >> c;
	i++;
	if ( i == n ) {
	  if (c != ']') is.clear(ios::badbit);
	} else {
	  if (c != ',') is.putback(c);
	}
      }
  }
  else {
    is.putback(c);
    is.clear(ios::badbit);
  }
  return is;
}

template<class Subscriptor, class T>
void ConcreteArray1d<Subscriptor, T>::setSizeOnHeap(Subscript n) {
  delete[] datap;
  datap = new T[n];
}


template<class Subscriptor, class T>
ConcreteArray1dRef<Subscriptor, T>& 
ConcreteArray1dRef<Subscriptor, T>::operator=(const T& rhs) {
    Subscript n = shape(0);
    while (n-- > 0) (*this)(n) = rhs;
    return *this;
}



template<class ArrayShape, class AnotherShape, class T>
void concreteCopy(
        ConcreteArray1dRef<ArrayShape, T> lhs, 
        ConcreteArray1dConstRef<AnotherShape, T> rhs
    ) {
    Subscript n = lhs.shape(0);
    if (n != rhs.shape(0)) throw ArrayErr::Shape();
    while (n-- > 0) lhs[n] = rhs[n];
}


template<class Subscriptor, class T>
ConcreteArray1dRef<Subscriptor, T>& 
ConcreteArray1dRef<Subscriptor, T>::operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs) {
  concreteCopy(*this, rhs);
  return *this;
}
 
template<class Subscriptor, class T>
void ConcreteArray1d<Subscriptor, T>::reshapeOnHeap(const SubscriptArray<1>& s) {
  setShape(s(0));
  setSizeOnHeap(numElts());
}

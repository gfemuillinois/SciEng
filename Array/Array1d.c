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

template<class T>
Array1d<T>& Array1d<T>::operator=(const ConstArray1d<T>& rhs) {
  // Same code as arrayCopy(); by duplicating it we can run with -qnotempinc XLC
  Subscript i = shape(0);
  if (i != rhs.shape(0)) throw ArrayErr::Shape();
  while (i-- > 0) (*this)(i) = rhs(i);
  return *this;
}

template<class T>
Array1d<T>& Array1d<T>::operator=(const T& rhs) {
  Subscript i = shape(0);
  while (i-- > 0) (*this)(i) = rhs;
  return *this;
}

template<class T>
ostream& operator<<(ostream& os, const ConstArray1d<T>& a) {
  return arrayTuplize(a, os);
}

template<class T>
istream& operator>>(istream& is, Array1d<T>& a) {
  char c = 0;
  is >> c;
  if (c == '[') {
      Subscript n = a.shape(0);
      int i = 0;
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


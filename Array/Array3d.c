/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayTuplize.h"

template<class T>
Array3d<T>& Array3d<T>::operator=(const ConstArray3d<T>& rhs) {
  Subscript i = shape(0);
  if (i != rhs.shape(0)) throw ArrayErr::Shape();
  while (i-- > 0) (*this)[i] = rhs[i];
  return *this;
}

template<class T>
Array3d<T>& Array3d<T>::operator=(const T& rhs) {
  Subscript i = shape(0);
  while (i-- > 0) (*this)[i] = rhs;
  return *this;
}

template<class T>
istream& operator>>(istream& is, Array3d<T>& a) {
  char c = 0;
  is >> c;
  if (c == '[') {
      Subscript n = a.shape(0);
      Subscript i = 0;
      while ( i < n ) {
        Array3d<T>::ProjectionT a_i = a[i];
	is >> a_i;
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

template<class T>
ostream& operator<<(ostream& os, const ConstArray3d<T>& a) {
  return arrayTuplize(a, os);
}

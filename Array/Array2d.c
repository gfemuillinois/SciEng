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
Array2d<T>& Array2d<T>::operator=(const ConstArray2d<T>& rhs) {
    Subscript i = shape(0);
    if (i != rhs.shape(0)) throw ArrayErr::Shape();
    while (i-- > 0) (*this)[i] = rhs[i];
    return *this;
}

template<class T>
Array2d<T>& Array2d<T>::operator=(const T& rhs) {
    Subscript i = shape(0);
    while (i-- > 0) (*this)[i] = rhs;
    return *this;
}


template<class T>
ostream& operator<<(ostream& os, const ConstArray2d<T>& a) {
  return arrayTuplize(a, os);
}

template<class T>
istream& operator>>(istream& is, Array2d<T>& a) {
  char c = 0;
  is >> c;
  if (c == '[') {
      Subscript n = a.shape(0);
      Subscript i = 0;
      while ( i < n ) {
        Array2d<T>::ProjectionT a_i = a[i];
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
ConstArray2d<T>::ConstProjectionT ConstArray2d<T>::operator[](Subscript i) const { return project(i, 0); }

template<class T>
ConstArray2d<T>::ConstProjectionT ConstArray2d<T>::row(Subscript i)        const { return project(i, 0); }

template<class T>
ConstArray2d<T>::ConstProjectionT ConstArray2d<T>::column(Subscript i)     const { return project(i, 1); }

template<class T>
Array2d<T>::ConstProjectionT Array2d<T>::operator[](Subscript i) const { return project(i, 0); }

template<class T>
Array2d<T>::ConstProjectionT Array2d<T>::row(Subscript i)        const { return project(i, 0); }

template<class T>
Array2d<T>::ConstProjectionT Array2d<T>::column(Subscript i)     const { return project(i, 1); }

template<class T>
Array2d<T>::ProjectionT Array2d<T>::operator[](Subscript i)  { return project(i, 0); }

template<class T>
Array2d<T>::ProjectionT Array2d<T>::row(Subscript i)         { return project(i, 0); }

template<class T>
Array2d<T>::ProjectionT Array2d<T>::column(Subscript i)      { return project(i, 1); }

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
std::ostream& 
operator<<(std::ostream& os, const ConcreteArray2dConstRef<Subscriptor, T>& a){
  return arrayTuplize(a, os);
}

template<class Subscriptor, class T>
std::istream& 
operator>>(std::istream& is, const ConcreteArray2dRef<Subscriptor, T>& a) {
  char c = 0;
  is >> c;
  if (c == '[') {
      Subscript n = a.shape(0);
      Subscript i = 0;
      while ( i < n ) {
        typename ConcreteArray2dRef<Subscriptor, T>::ProjectionT a_i = a[i];
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
ConstConcreteArrayProjection1d< Subscriptor, T >
ConcreteArray2dConstRef<Subscriptor, T>::project(Subscript s, Dimension d) const {
   SubscriptArray<2> pjs(0,0);
   pjs(d) = s;
   return ConstConcreteArrayProjection1d< Subscriptor, T >(
     projectionSubscriptor(d, s),
     firstDatum()+offset(pjs)
  );
}


template<class Subscriptor, class T>
ConcreteArrayProjection1d< Subscriptor, T >
ConcreteArray2dRef<Subscriptor, T>::project(Subscript s, Dimension d) const { 
    SubscriptArray<2> pjs(0,0);
    pjs(d) = s;
    return ConcreteArrayProjection1d< Subscriptor, T >( 
        projectionSubscriptor(d, s),
        firstDatum()+offset(pjs)
    );
}




template<class ArrayShape, class AnotherShape, class T>
void concreteCopy( 
        const ConcreteArray2dRef<ArrayShape, T>& lhs, 
        const ConcreteArray2dConstRef<AnotherShape, T>& rhs
    ) {
    Subscript n = lhs.shape(0);
    if (n != rhs.shape(0)) throw ArrayErr::Shape();
    while (n-- > 0) concreteCopy(lhs[n], rhs[n]);
}



template<class Subscriptor, class T>
const ConcreteArray2dRef<Subscriptor, T>& 
ConcreteArray2dRef<Subscriptor, T>::operator=(const T& rhs) const {
    Subscript n = shape(0);
    while (n-- > 0) (*this)[n] = rhs;
    return *this;
}



template<class Subscriptor, class T>
const ConcreteArray2dRef<Subscriptor, T>&
ConcreteArray2dRef<Subscriptor, T>::operator=(
        const ConcreteArray2dConstRef<Subscriptor, T>& rhs) const {
    concreteCopy(*this, rhs);
    return *this;
}

template<class Subscriptor, class T>
const ConcreteArray2dRef<Subscriptor, T>&
ConcreteArray2dRef<Subscriptor, T>::operator=(
        const ConcreteArray2dRef<Subscriptor, T>& rhs) const {
    // Convert rhs reference to const reference and use its assignment
    const ConcreteArray2dConstRef<Subscriptor, T> rhsa = rhs;
    return *this = rhs;
}



template<class Subscriptor, class T>
void ConcreteArray2d<Subscriptor, T>::setSizeOnHeap(Subscript n) {
    if (n < 0) throw ArrayErr::NegativeSize();
    delete[] datap;
    if (n>0)
      datap = new T[n];
    else
      datap = 0;
}

template<class Subscriptor, class T>
void ConcreteArray2d<Subscriptor, T>::reshapeOnHeap(const SubscriptArray<2>& s) {
    setShape(s);
    setSizeOnHeap(numElts());
}

template<class Subscriptor, class T>
void ConcreteArray2d<Subscriptor, T>::swap( ConcreteArray2d<Subscriptor, T>&
					    rhs ) {

  // swap the Subscriptor
  SubscriptArray<2> subs_temp = the_shape;
  setShape( rhs.the_shape );
  rhs.setShape( subs_temp );

  // swap the data
  T* datap_temp = datap;
  datap = rhs.datap;
  rhs.datap = datap_temp;
}

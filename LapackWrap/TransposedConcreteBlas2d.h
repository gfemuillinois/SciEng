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
class TransposedConcreteBlas2d;

template<class T>
ConcreteBlas2d<T> operator*(const TransposedConcreteBlas2d<T>& t, const TransposedConcreteBlas2d<T>& u);
// same as above: C = A^t * B^t
template<class T>
void mult(const TransposedConcreteBlas2d<T>& A, const TransposedConcreteBlas2d<T>& B, 
	     ConcreteBlas2d<T>& C );

template<class T>
ConcreteBlas2d<T> operator*(const ConcreteBlas2d<T>& u, const TransposedConcreteBlas2d<T>& t);
// same as above: C = A * B^t
template<class T>
void mult(const ConcreteBlas2d<T>& A, const TransposedConcreteBlas2d<T>& B, 
	  ConcreteBlas2d<T>& C );

template<class T>
ConcreteBlas2d<T> operator*(const TransposedConcreteBlas2d<T>& t, const ConcreteBlas2d<T>& u);
// same as above: C = A^t * B
template<class T>
void mult(const TransposedConcreteBlas2d<T>& A, const ConcreteBlas2d<T>& B, 
	  ConcreteBlas2d<T>& C );

template<class T>
ConcreteBlas1d<T> operator*(const TransposedConcreteBlas2d<T>& t, const ConcreteBlas1d<T>& u);
// same as above: c = A^t * c
template<class T>
void mult(const TransposedConcreteBlas2d<T>& A, const ConcreteBlas1d<T>& b, 
	  ConcreteBlas1d<T>& c );


template<class T>
class TransposedConcreteBlas2d :               
    public ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, T> {
public:
  typedef ConcreteRowMajorSubscriptor<2> SubscriptorType;

  explicit TransposedConcreteBlas2d(ConcreteBlas2d<T>& a);


  friend ConcreteBlas2d<T> operator*<T>(const TransposedConcreteBlas2d<T>& t, 
					const TransposedConcreteBlas2d<T>& u);
  // same as above: C = A^t * B^t
  friend void mult<T>(const TransposedConcreteBlas2d<T>& A, 
		      const TransposedConcreteBlas2d<T>& B, 
		      ConcreteBlas2d<T>& C );

  friend ConcreteBlas2d<T> operator*<T>(const ConcreteBlas2d<T>& u,
					const TransposedConcreteBlas2d<T>& t);
  // same as above: C = A * B^t
  friend void mult<T>(const ConcreteBlas2d<T>& A, 
		      const TransposedConcreteBlas2d<T>& B, 
		      ConcreteBlas2d<T>& C );

  friend ConcreteBlas2d<T> operator*<T>(const TransposedConcreteBlas2d<T>& t, 
					const ConcreteBlas2d<T>& u);
  // same as above: C = A^t * B
  friend void mult<T>(const TransposedConcreteBlas2d<T>& A, 
		      const ConcreteBlas2d<T>& B, 
		      ConcreteBlas2d<T>& C );

  friend ConcreteBlas1d<T> operator*<T>(const TransposedConcreteBlas2d<T>& t, 
					const ConcreteBlas1d<T>& u);
  // same as above: c = A^t * c
  friend void mult<T>(const TransposedConcreteBlas2d<T>& A, 
		      const ConcreteBlas1d<T>& b, 
		      ConcreteBlas1d<T>& c );


  //CAD operator ConcreteBlas2d<T>() const;
};


template<class T>
inline
ostream& operator<<(ostream& os, const TransposedConcreteBlas2d<T>& a) {
  return os << ConcreteArray2dConstRef< typename TransposedConcreteBlas2d<T>::SubscriptorT, T>(a);
}

#ifdef XLC_QNOTEMPINC
#include "LapackWrap/TransposedConcreteBlas2d.c"
#endif
      
#endif

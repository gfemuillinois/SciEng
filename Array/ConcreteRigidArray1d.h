/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteRigidArray1dH
#define ConcreteRigidArray1dH

#ifdef SCIENG_CHECK_SUBSCRIPTS
#include <assert.h>
#include <iostream>
#else
#include <iosfwd>
#endif

#include "SciEng/Subscript.h"
#include "SciEng/ArrayErr.h"
//#include "Array/ConcreteArray1d.h"
//#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArrayIterator.h"


template<class T, Subscript n0>
class ConcreteRigidArray1d { 
 public:
  ConcreteRigidArray1d() {}
  explicit ConcreteRigidArray1d(Subscript s0) { 
    if (n0 != s0) throw ArrayErr::CreationSize(); }

  // copy constructor provides deep copy
 ConcreteRigidArray1d(const ConcreteRigidArray1d<T, n0>& rhs);

#ifdef SCIENG_CHECK_SUBSCRIPTS
  void check_subscripts(const Subscript s) const {
    if ( s<0 || s >= shape(0) ) {
      std::cerr << "ConcreteRigidArray1d<T,n0>::check_subscripts: Invalid arg:"
	   << s << "\nshape(0) = " << shape(0) << std::endl;
      assert(0);
    }
  }
#endif

  Dimension         dim()              const { return 1;    }  
  Subscript         shape(Dimension d) const { return n0;   }
  Subscript         numElts()          const { return n0;   }
  Subscript         offset(const Subscript s) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s);
#endif
 return s; }   


  typedef T EltT;
  typedef const EltT& ConstProjectionT;
  typedef EltT& ProjectionT;
  typedef ConcreteArrayBrowser< ConcreteRigidArray1d<T, n0> >  BrowserType;
  typedef ConcreteArrayIterator< ConcreteRigidArray1d<T, n0>  > IteratorType;

  const EltT&      operator()(Subscript s) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s);
#endif
    return data[s]; }

  ConstProjectionT operator[](Subscript s) const { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s);
#endif
    return data[s]; }

  EltT&       operator()(Subscript s) { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s);
#endif
    return data[s]; }

  ProjectionT operator[](Subscript s) { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s);
#endif
    return data[s]; }

  T const * firstDatum() const { return data; }
  T*        firstDatum()       { return data; }

  ConcreteRigidArray1d<T, n0>& operator=(const T& rhs);
  ConcreteRigidArray1d<T, n0>& operator=(const ConcreteRigidArray1d<T, n0>& rhs);

protected:
  T data[n0];

};

template<class T, Subscript n0>
std::ostream& 
operator<<(std::ostream& os, const ConcreteRigidArray1d<T, n0>& a);

template<class T, Subscript n0>
inline
ConcreteRigidArray1d<T,n0>& ConcreteRigidArray1d<T,n0>::operator=(const T& rhs) {
  /*  for ( IteratorType i(*this); i.more(); i.advance() ) {
    i.current() = rhs;
  }*/

  Subscript n = shape(0);
  while (n-- > 0) (*this)(n) = rhs;

  //while (n-- > 0) data[n] = rhs;
  //  for(Subscript i=0; i<n0; ++i) data[i] = rhs;
  
  return *this;
}

template<class T, Subscript n0>
inline
ConcreteRigidArray1d<T,n0>& 
ConcreteRigidArray1d<T,n0>::operator=(const ConcreteRigidArray1d<T, n0>& rhs) {
  Subscript n = shape(0);
  if (n != rhs.shape(0)) throw ArrayErr::Shape();
  while (n-- > 0) (*this)[n] = rhs[n];

  return *this;
}

template<class T, Subscript n0>
inline
ConcreteRigidArray1d<T,n0>::ConcreteRigidArray1d
(const ConcreteRigidArray1d<T, n0>& rhs) {

  // copy constructor provides deep copy

  Subscript n = shape(0);
  if (n != rhs.shape(0)) throw ArrayErr::Shape();
  while (n-- > 0) (*this)[n] = rhs[n];

}

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteRigidArray1d.c"
#endif

#endif

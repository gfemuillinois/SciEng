/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteRigidArray3dH
#define ConcreteRigidArray3dH

#ifdef SCIENG_CHECK_SUBSCRIPTS
#include <assert.h>
#include <iostream>
#endif

#include "Array/SubscriptArray.h"
#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArrayProjection2d.h"
#include "Array/ConcreteArrayIterator.h"
#include "SciEng/ArrayErr.h"

template<class T, Subscript n0, Subscript n1, Subscript n2>
class ConcreteRigidArray3d { 
 public:
  ConcreteRigidArray3d() {}
  ConcreteRigidArray3d(Subscript s0, Subscript s1, Subscript s2);
  typedef T EltT;

#ifdef SCIENG_CHECK_SUBSCRIPTS
  void check_subscripts(const Subscript s0, const Subscript s1, 
			const Subscript s2) const {
    if ( s0<0 || s0 >= shape(0) || s1<0 || s1 >= shape(1) ||
	 s2<0 || s2 >= shape(2)) {
      cerr << "ConcreteRigidArray2d<T,n0,n1,n2>::check_subscripts: Invalid "
	   << "args: " << s0 << "  " << s1 << "  " << s2
	   << "\nshape(0) = " << shape(0) << " shape(1) = " << shape(1) 
	   << " shape(2) = " << shape(2) << endl;
      assert(0);
    }
  }
#endif

  Dimension  dim()              const { return 3;                            }
  Subscript  shape(Dimension d) const;
  Subscript  numElts()          const { return n0*n1*n2;                     }
  Subscript  offset(const SubscriptArray<3>& s) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s(0), s(1), s(2));
#endif
    return s(2) + n2*(s(1) + n1*s(0));   }  
  
  
  typedef ConcreteRowMajorSubscriptor<3>                     Subscriptor;
  typedef ConstConcreteArrayProjection2d<Subscriptor, EltT > ConstProjectionT;
  typedef ConcreteArrayProjection2d<Subscriptor, EltT >      ProjectionT;
  typedef ConcreteArrayBrowser< ConcreteRigidArray3d<T, n0, n1, n2> >   BrowserType;
  typedef ConcreteArrayIterator< ConcreteRigidArray3d<T, n0, n1, n2>  > IteratorType;

  ConstProjectionT project(Subscript, Dimension = 0) const;
  ProjectionT      project(Subscript, Dimension = 0);

  ConstProjectionT operator[](Subscript s) const  { return project(s, 0); }
  ProjectionT      operator[](Subscript s)        { return project(s, 0); }

  const T& operator()(Subscript s0, Subscript s1, Subscript s2) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s0, s1, s2);
#endif
    return data[s0][s1][s2]; }

  T& operator()(Subscript s0, Subscript s1, Subscript s2)  {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s0, s1, s2);
#endif
    return data[s0][s1][s2]; }

  T const * firstDatum()  const { return &data[0][0][0]; }
  T       * firstDatum()        { return &data[0][0][0]; }
  
  ConcreteRigidArray3d<T, n0, n1, n2>& operator=(const T& rhs);
 protected:
  T data[n0][n1][n2];
};

template<class T, Subscript n0, Subscript n1, Subscript n2>
ostream& operator<<(ostream& os, const ConcreteRigidArray3d<T, n0, n1, n2>& a);

template<class T, Subscript n0, Subscript n1, Subscript n2>
inline
Subscript ConcreteRigidArray3d<T, n0, n1, n2>::shape(Dimension d) const {
  switch(d) {
  case 0: return n0;
  case 1: return n1;
  case 2: return n2;
  default: return 0;
  }
}
#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteRigidArray3d.c"
#endif

#endif

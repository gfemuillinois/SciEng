/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteRigidArray2dH
#define ConcreteRigidArray2dH
                      
#ifdef SCIENG_CHECK_SUBSCRIPTS
#include <assert.h>
#include <iostream>
#else
#include <iosfwd>
#endif

#include "Array/SubscriptArray.h"
#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArrayProjection1d.h"
#include "Array/ConcreteArrayIterator.h"
#include "SciEng/ArrayErr.h"

template<class T, Subscript n0, Subscript n1>
class ConcreteRigidArray2d {
public:
  ConcreteRigidArray2d() {}
  ConcreteRigidArray2d(Subscript s0, Subscript s1) { 
    if (s0 != n0 || s1 != n1) throw ArrayErr::CreationSize();}

  // Deep copy is done here
 ConcreteRigidArray2d(const ConcreteRigidArray2d<T, n0, n1>& rhs);

#ifdef SCIENG_CHECK_SUBSCRIPTS
  void check_subscripts(const Subscript s0, const Subscript s1) const {
    if ( s0<0 || s0 >= shape(0) || s1<0 || s1 >= shape(1) ) {
      std::cerr << "ConcreteRigidArray2d<T,n0,n1>::check_subscripts: Invalid args: " 
	   << s0 << "  " << s1 << "\nshape(0) = " << shape(0) 
	   << " shape(1) = " << shape(1) << std::endl;
      assert(0);
    }
  }
#endif 

  Dimension         dim()              const { return 2;                        }
  Subscript         shape(Dimension d) const { return (d==0)? n0 : n1;          }
  Subscript         numElts()          const { return n0*n1;                    }
  Subscript         offset(const SubscriptArray<2>& s) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s(0), s(1));
#endif
    return s(1) + n1*s(0); }

  Subscript         offset(const Subscript s0, const Subscript s1) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s0, s1);
#endif
    return s1 + n1*s0; }

  typedef T                                                    EltT;
  typedef ConcreteRowMajorSubscriptor<2>                       SubscriptorT;
  typedef ConstConcreteArrayProjection1d< SubscriptorT, EltT > ConstProjectionT;
  typedef ConcreteArrayProjection1d< SubscriptorT, EltT >      ProjectionT;
  typedef ConcreteArrayBrowser< ConcreteRigidArray2d<T, n0, n1> >   BrowserType;
  typedef ConcreteArrayIterator< ConcreteRigidArray2d<T, n0, n1>  > IteratorType;

  ConstProjectionT project(Subscript, Dimension = 0) const;
  ProjectionT      project(Subscript, Dimension = 0);

  ConstProjectionT operator[](Subscript s) const { return project(s, 0); }
  ProjectionT      operator[](Subscript s)       { return project(s, 0); }

  const EltT& operator()(Subscript s0, Subscript s1) const { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s0, s1);
#endif
    return datap[s0][s1]; }

  EltT& operator()(Subscript s0, Subscript s1)   {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    check_subscripts(s0, s1);
#endif
    return datap[s0][s1]; }

  T const * firstDatum()  const { return &datap[0][0]; }
  T       * firstDatum()        { return &datap[0][0]; }

  ConcreteRigidArray2d<T, n0, n1>& operator=(const T& rhs);
  ConcreteRigidArray2d<T, n0, n1>& operator=(const ConcreteRigidArray2d<T, n0, n1>& rhs);

protected:
  T datap[n0][n1];
};

template<class T, Subscript n0, Subscript n1>
std::ostream& 
operator<<(std::ostream& os, const ConcreteRigidArray2d<T, n0, n1>& a);

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteRigidArray2d.c"
#endif

#endif

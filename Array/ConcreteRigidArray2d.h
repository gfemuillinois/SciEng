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

  Dimension         dim()              const { return 2;                        }
  Subscript         shape(Dimension d) const { return (d==0)? n0 : n1;          }
  Subscript         numElts()          const { return n0*n1;                    }
  Subscript         offset(const SubscriptArray<2>& s)
    const { return s(1) + n1*s(0);           }
  Subscript         offset(const Subscript s0, const Subscript s1)
    const { return s1 + n1*s0;           }

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

  const EltT& operator()(Subscript s0, Subscript s1) const { return datap[s0][s1]; }
  EltT& operator()(Subscript s0, Subscript s1)       { return datap[s0][s1]; }

  T const * firstDatum()  const { return &datap[0][0]; }
  T       * firstDatum()        { return &datap[0][0]; }

  ConcreteRigidArray2d<T, n0, n1>& operator=(const T& rhs);
  ConcreteRigidArray2d<T, n0, n1>& operator=(const ConcreteRigidArray2d<T, n0, n1>& rhs);

 protected:
  T datap[n0][n1];
};

template<class T, Subscript n0, Subscript n1>
ostream& operator<<(ostream& os, const ConcreteRigidArray2d<T, n0, n1>& a);

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteRigidArray2d.c"
#endif

#endif

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

#include "SciEng/ArrayErr.h"
#include "Array/ConcreteArray1d.h"
#include "Array/ConcreteArrayShape.h"
#include "Array/ConcreteArrayIterator.h"


template<class T, Subscript n0>
class ConcreteRigidArray1d { 
    public:
    ConcreteRigidArray1d() {}
    ConcreteRigidArray1d(Subscript s0) { if (n0 != s0) throw ArrayErr::CreationSize(); }


    Dimension         dim()              const { return 1;    }  
    Subscript         shape(Dimension d) const { return n0;   }
    Subscript         numElts()          const { return n0;   }
    Subscript         offset(const SubscriptArray<1>& s)
                                         const { return s(0); }   


    typedef T EltT;
    typedef const EltT& ConstProjectionT;
    typedef EltT& ProjectionT;
    typedef ConcreteArrayBrowser< ConcreteRigidArray1d<T, n0> >  BrowserType;
    typedef ConcreteArrayIterator< ConcreteRigidArray1d<T, n0>  > IteratorType;

    const EltT&      operator()(Subscript s) const { return data[s]; }
    ConstProjectionT operator[](Subscript s) const { return data[s]; }

    EltT&       operator()(Subscript s) { return data[s]; }
    ProjectionT operator[](Subscript s) { return data[s]; }

    T const * firstDatum() const { return data; }
    T*        firstDatum()       { return data; }

    ConcreteRigidArray1d<T, n0>& operator=(const T& rhs);
    protected:
    T data[n0];
    };

    template<class T, Subscript n0>
    ostream& operator<<(ostream& os, const ConcreteRigidArray1d<T, n0>& a);

    #ifdef XLC_QNOTEMPINC
    #include "Array/ConcreteRigidArray1d.c"
    #endif

    #endif

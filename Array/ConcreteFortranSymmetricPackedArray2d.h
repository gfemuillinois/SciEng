/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteFortranSymmetricPackedArray2dH
#define ConcreteFortranSymmetricPackedArray2dH

#include "Array/ConcreteArray2d.h"


class FortranSymmetricPackedSubscriptor {
public:
    FortranSymmetricPackedSubscriptor(const SubscriptArray<2>& s);

    Dimension         dim()            const { return 2;               }
    Subscript         shape(Dimension) const { return n;               }
    Subscript         numElts()        const { return (n * (n+1)) / 2; }
    void              setShape(const SubscriptArray<2>& s);


    Subscript offset(const SubscriptArray<2>& s) const;
  Subscript offset(const Subscript s0, const Subscript s1) const; // TBremoved

    class ProjectionT {
    public:
        ProjectionT(const FortranSymmetricPackedSubscriptor&, Dimension, Subscript);

        Dimension         dim()            const { return 1; }
        Subscript         shape(Dimension) const { return n; }
        Subscript         numElts()        const { return n; }

        Subscript offset(const SubscriptArray<1>& s) const;
        Subscript offset(const Subscript s) const;
    private:

        const Subscript proj_sub;    // Subscript in projected-out dimension
        const Dimension d;           // Projected-out dimension
        const Subscript n;           // Number of elements in projection

    };

    ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
protected:
    Subscript n;
};



inline
Subscript 
FortranSymmetricPackedSubscriptor::offset(const SubscriptArray<2>& s) const {
        Subscript i = s(0);
        Subscript j = s(1);
        return i <= j ? i+(j*(j+1))/2 : j+(i*(i+1))/2;
}

inline
Subscript 
FortranSymmetricPackedSubscriptor::offset(const Subscript s0, const Subscript s1) const {
        Subscript i = s0;
        Subscript j = s1;
        return i <= j ? i+(j*(j+1))/2 : j+(i*(i+1))/2;
}


inline
FortranSymmetricPackedSubscriptor::ProjectionT 
FortranSymmetricPackedSubscriptor::
projectionSubscriptor(Dimension d, Subscript s) const { 
    return ProjectionT(*this, d, s); 
}



template<class T>
class ConcreteFortranSymmetricPackedArray2d :
    public ConcreteArray2d<FortranSymmetricPackedSubscriptor, T> {
public:
  typedef FortranSymmetricPackedSubscriptor SubscriptorType;

    ConcreteFortranSymmetricPackedArray2d(Subscript s0, Subscript s1);
    ConcreteFortranSymmetricPackedArray2d(const ConcreteFortranSymmetricPackedArray2d<T>&);

    ~ConcreteFortranSymmetricPackedArray2d();

    ConcreteFortranSymmetricPackedArray2d<T>& operator=(const ConcreteFortranSymmetricPackedArray2d<T>& rhs);
    ConcreteFortranSymmetricPackedArray2d<T>& operator=(const T& rhs);

    void reshape(const SubscriptArray<2>& s) { reshapeOnHeap(s); }
};


#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteFortranSymmetricPackedArray2d.c"
#endif

#endif


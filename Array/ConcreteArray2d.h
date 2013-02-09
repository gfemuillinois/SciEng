/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArray2dH
#define ConcreteArray2dH
                      
#include "Array/ConcreteArrayIterator.h"
#include "Array/ArrayIterator2d.h"
#include "Array/Array2d.h"
#include "Array/ConcreteArrayProjection1d.h"

template<class Subscriptor, class T> class ConcreteArray2dRef;
template<class Subscriptor, class T> class ConcreteArray2d;


template<class Subscriptor, class T>
class ConcreteArray2dConstRef :
    private Subscriptor {
public:
    using Subscriptor::dim;
    using Subscriptor::shape;
    using Subscriptor::numElts;
    using Subscriptor::offset;

    using Subscriptor::projectionSubscriptor;

    typedef T                                                          EltT;
    typedef Subscriptor                                                SubscriptorT;
    typedef ConstConcreteArrayProjection1d<Subscriptor, T>             ConstProjectionT;
    typedef ArrayBrowser2d< ConcreteArray2dConstRef<Subscriptor, T> >  BrowserType;


    const T& operator()(Subscript s0, Subscript s1) const { 
        return firstDatum()[offset( s0, s1 )]; 
    }                  

    ConstProjectionT project(Subscript, Dimension) const;


    ConstProjectionT operator[](Subscript s) const { return project(s, 0); }
    ConstProjectionT row(Subscript s)        const { return project(s, 0); }
    ConstProjectionT column(Subscript s)     const { return project(s, 1); }


    const T* firstDatum() const { return datap; }

    Subscriptor subscriptor() const { return *this; }
protected:
    ConcreteArray2dConstRef(Subscriptor s, const T* p) : Subscriptor(s), datap(p) {}
    friend class ConcreteArray2dRef<Subscriptor, T>;
    friend class ConcreteArray2d<Subscriptor, T>;
private:
    void operator=(const ConcreteArray2dConstRef<Subscriptor, T>&);// Prohibit
private:
    const T* const datap;
};



template<class Subscriptor, class T>
class ConcreteArray2dRef :      
    private Subscriptor {
public:
    using Subscriptor::dim;
    using Subscriptor::shape;
    using Subscriptor::numElts;
    using Subscriptor::offset;

    using Subscriptor::projectionSubscriptor;

    typedef T           EltT;
    typedef Subscriptor SubscriptorT;



    typedef ConstConcreteArrayProjection1d<Subscriptor, T> ConstProjectionT;
    typedef ConcreteArrayProjection1d<Subscriptor, T>      ProjectionT;



    typedef ArrayBrowser2d< ConcreteArray2dRef<Subscriptor, T> >  BrowserType;
    typedef ArrayIterator2d< ConcreteArray2dRef<Subscriptor, T> > IteratorType;



    T&          operator()(Subscript s0, Subscript s1) const;
    Subscriptor subscriptor()                          const { return *this; }
    T*          firstDatum()                           const { return datap; }



    ProjectionT project(Subscript, Dimension) const;

    ProjectionT operator[](Subscript s)       const { return project(s, 0); }
    ProjectionT row(Subscript s)              const { return project(s, 0); }
    ProjectionT column(Subscript s)           const { return project(s, 1); }


    operator ConcreteArray2dConstRef<Subscriptor, T>() const;

    const ConcreteArray2dRef<Subscriptor, T>& operator=(
            const ConcreteArray2dConstRef<Subscriptor, T>& rhs) const;
    const ConcreteArray2dRef<Subscriptor, T>& operator=(
            const ConcreteArray2dRef<Subscriptor, T>& rhs) const;
    const ConcreteArray2dRef<Subscriptor, T>& operator=(const T& rhs) const;
protected:
    ConcreteArray2dRef(Subscriptor s, T* p) : Subscriptor(s), datap(p) {}
    friend class ConcreteArray2d<Subscriptor, T>;
private:
    T* const datap;
};


template<class Subscriptor, class T>
inline T& ConcreteArray2dRef<Subscriptor, T>::operator()(Subscript s0, Subscript s1) const {
    return firstDatum()[offset( s0, s1 )]; 
}


template<class Subscriptor, class T>
inline 
ConcreteArray2dRef<Subscriptor, T>::operator ConcreteArray2dConstRef<Subscriptor, T>() const {
    return ConcreteArray2dConstRef<Subscriptor, T>(*this, datap);
}



template<class Subscriptor, class T>
class ConcreteArray2d :      
    private Subscriptor {
public:
    using Subscriptor::dim;
    using Subscriptor::shape;
    using Subscriptor::numElts;
    using Subscriptor::offset;
    using Subscriptor::setShape;

    typedef T                                                         EltT;
    typedef Subscriptor                                               SubscriptorT;

    typedef ConcreteArrayProjection1d< Subscriptor, T >               ProjectionT;
    typedef ConstConcreteArrayProjection1d< Subscriptor, T >          ConstProjectionT;

    typedef ConcreteArrayBrowser< ConcreteArray2d<Subscriptor, T> >   BrowserType;
    typedef ConcreteArrayIterator< ConcreteArray2d<Subscriptor, T> >  IteratorType;

    const T& operator()(Subscript s0, Subscript s1) const;
    T&       operator()(Subscript s0, Subscript s1);


    Subscriptor subscriptor() const { return *this; }

    T const * firstDatum()  const { return datap; }
    inline T       * firstDatum()        { return datap; }

    ConstProjectionT project(Subscript s, Dimension d) const;
    ProjectionT      project(Subscript s, Dimension d);

    ConstProjectionT operator[](Subscript s) const { return project(s, 0); }
    ProjectionT      operator[](Subscript s)       { return project(s, 0); }

    ConstProjectionT row(Subscript i)        const { return project(i, 0); }
    ProjectionT      row(Subscript i)              { return project(i, 0); }

    ConstProjectionT column(Subscript i)     const { return project(i, 1); }
    ProjectionT      column(Subscript i)           { return project(i, 1); }

    operator ConcreteArray2dConstRef<Subscriptor, T>() const;
    operator ConcreteArray2dRef<Subscriptor, T>();

    ConcreteArray2d<Subscriptor, T>& operator=(const ConcreteArray2d<Subscriptor, T>& rhs);
    ConcreteArray2d<Subscriptor, T>& operator=(const ConcreteArray2dConstRef<Subscriptor, T>& rhs);
    ConcreteArray2d<Subscriptor, T>& operator=(const T& rhs);

  void swap( ConcreteArray2d<Subscriptor, T>& rhs );

protected:
    ConcreteArray2d(const Subscriptor& s, T* p) : Subscriptor(s), datap(p) {}
    void reshapeOnHeap(const SubscriptArray<2>& s);
    void setSizeOnHeap(Subscript n);

  using Subscriptor::the_shape;

protected:
    T* datap;
private:
    ConcreteArray2d(const ConcreteArray2d<Subscriptor,T>&);
};



template<class Subscriptor, class T>
inline 
const T& ConcreteArray2d<Subscriptor, T>::operator()(Subscript s0, Subscript s1) const {

  //  return firstDatum()[offset(SubscriptArray<2>(s0, s1))];
  //return datap[offset(s0, s1)];

  return firstDatum()[offset(s0, s1)]; // faster than using datap.  why?
}

template<class Subscriptor, class T>
inline 
T& ConcreteArray2d<Subscriptor, T>::operator()(Subscript s0, Subscript s1) {

  //  return firstDatum()[offset(SubscriptArray<2>(s0, s1))];
  // return datap[offset(s0, s1) ];

  return firstDatum()[ offset(s0, s1) ]; // faster than using datap. Why?
}


                               
template<class Subscriptor, class T>
inline typename ConcreteArray2d<Subscriptor, T>::ConstProjectionT 
ConcreteArray2d<Subscriptor, T>::project(Subscript s, Dimension d) const {
   return ConcreteArray2dConstRef<Subscriptor, T>(*this).project(s, d);
} 


template<class Subscriptor, class T>
inline typename
ConcreteArray2d<Subscriptor, T>::ProjectionT 
ConcreteArray2d<Subscriptor, T>::project(Subscript s, Dimension d) {
    return ConcreteArray2dRef<Subscriptor, T>(*this).project(s, d);
}

   

template<class Subscriptor, class T>
inline ConcreteArray2d<Subscriptor, T>& 
ConcreteArray2d<Subscriptor, T>::operator=(const ConcreteArray2dConstRef<Subscriptor, T>& rhs) {
    ConcreteArray2dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

template<class Subscriptor, class T>
inline ConcreteArray2d<Subscriptor, T>&
ConcreteArray2d<Subscriptor, T>::operator=(const ConcreteArray2d<Subscriptor, T>& rhs) {
    ConcreteArray2dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

template<class Subscriptor, class T>
inline ConcreteArray2d<Subscriptor, T>& 
ConcreteArray2d<Subscriptor, T>::operator=(const T& rhs) {
    ConcreteArray2dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}



template<class Subscriptor, class T>
inline 
ConcreteArray2d<Subscriptor, T>::operator ConcreteArray2dConstRef<Subscriptor, T>() const {
    return ConcreteArray2dConstRef<Subscriptor, T>(subscriptor(), datap);
}

template<class Subscriptor, class T>
inline 
ConcreteArray2d<Subscriptor, T>::operator ConcreteArray2dRef<Subscriptor, T>() {
    return ConcreteArray2dRef<Subscriptor, T>(subscriptor(), datap);
}

   
template<class Subscriptor, class T>
std::ostream& operator<<(std::ostream& os, const ConcreteArray2dConstRef<Subscriptor, T>& a);

template<class Subscriptor, class T>
std::istream& operator>>(std::istream& is, const ConcreteArray2dRef<Subscriptor, T>& a);

template<class Subscriptor, class T>
inline
std::ostream& operator<<(std::ostream& os, const ConcreteArray2d<Subscriptor, T>& a) {
  return os << ConcreteArray2dConstRef<Subscriptor, T>(a);
}

template<class Subscriptor, class T>
inline
std::istream& operator>>(std::istream& is, ConcreteArray2d<Subscriptor, T>& a) {
  return is >> ConcreteArray2dRef<Subscriptor, T>(a);
}

template<class ArrayShape, class AnotherShape, class T>
void concreteCopy(const ConcreteArray2dRef<ArrayShape, T>& lhs, const ConcreteArray2dConstRef<AnotherShape, T >& rhs);

template<class ArrayShape, class AnotherShape, class T>
inline
void concreteCopy(ConcreteArray2d<ArrayShape, T>& lhs, const ConcreteArray2d<AnotherShape, T>& rhs) {
  concreteCopy(ConcreteArray2dRef<ArrayShape, T>(lhs), ConcreteArray2dConstRef<AnotherShape, T>(rhs));
}

template<class ArrayShape, class AnotherShape, class T>
inline
void concreteCopy(ConcreteArray2d<ArrayShape, T>& lhs, const ConcreteArray2dConstRef<AnotherShape, T>& rhs) {
  concreteCopy(ConcreteArray2dRef<ArrayShape, T>(lhs), rhs);
}

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArray2d.c"
#endif

#endif

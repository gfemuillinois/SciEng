/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArray3dH
#define ConcreteArray3dH
                      
#include "Array/ConcreteArrayIterator.h"
#include "Array/ArrayIterator3d.h"
#include "Array/ConcreteArrayProjection2d.h"


template<class Subscriptor, class T> class ConcreteArray3dRef;
template<class Subscriptor, class T> class ConcreteArray3d;

template<class Subscriptor, class T>
class ConcreteArray3dConstRef :
  private Subscriptor {
public:
  Subscriptor::dim;
  Subscriptor::shape;
  Subscriptor::numElts;
  Subscriptor::offset;

  Subscriptor::projectionSubscriptor;

  typedef T           EltT;
  typedef Subscriptor SubscriptorT;
  typedef ConstConcreteArrayProjection2d<Subscriptor, T> ConstProjectionT;
  typedef ArrayBrowser3d< ConcreteArray3dConstRef<Subscriptor, T> >  BrowserType;

  const T& operator()(Subscript s0, Subscript s1, Subscript s2) const { 
    return firstDatum()[offset(SubscriptArray<3>(s0, s1, s2))]; 
  }                  

  ConstProjectionT project(Subscript, Dimension) const;
  ConstProjectionT operator[](Subscript s) const { return project(s, 0); }
  ConstProjectionT row(Subscript s)    const     { return project(s, 0); }
  ConstProjectionT column(Subscript s) const     { return project(s, 1); }
  ConstProjectionT plane(Subscript s) const      { return project(s, 2); }
  
  const T* firstDatum() const { return datap; }

  Subscriptor subscriptor() const { return *this; }
protected:
  ConcreteArray3dConstRef(Subscriptor s, const T* p) : Subscriptor(s), datap(p) {}
  friend class ConcreteArray3dRef<Subscriptor, T>;
  friend class ConcreteArray3d<Subscriptor, T>;
private:
  void operator=(const ConcreteArray3dConstRef<Subscriptor, T>&);   // Prohibit
private:
  const T* const datap;
};

template<class Subscriptor, class T>
class ConcreteArray3dRef :
  private Subscriptor {
public:
  Subscriptor::dim;
  Subscriptor::shape;
  Subscriptor::numElts;
  Subscriptor::offset;

  Subscriptor::projectionSubscriptor;

  typedef T           EltT;
  typedef Subscriptor SubscriptorT;
  typedef ConstConcreteArrayProjection2d<Subscriptor, T> ConstProjectionT;
  typedef ConcreteArrayProjection2d<Subscriptor, T> ProjectionT;
  typedef ArrayBrowser3d< ConcreteArray3dRef<Subscriptor, T> >  BrowserType;
  typedef ArrayIterator3d< ConcreteArray3dRef<Subscriptor, T> >  IteratorType;

  T& operator()(Subscript s0, Subscript s1, Subscript s2) const { 
    return firstDatum()[offset(SubscriptArray<3>(s0, s1, s2))]; 
  }                  

  ProjectionT project(Subscript, Dimension) const;
  ProjectionT operator[](Subscript s) const { return project(s, 0); }
  ProjectionT row(Subscript s)        const { return project(s, 0); }
  ProjectionT column(Subscript s)     const { return project(s, 1); }
  ProjectionT plane(Subscript s)      const { return project(s, 2); }
  
  T* firstDatum() const { return datap; }

  Subscriptor subscriptor() const { return *this; }

  operator ConcreteArray3dConstRef<Subscriptor, T>() const {
    return ConcreteArray3dConstRef<Subscriptor, T>(*this, datap);
  }
  
  ConcreteArray3dRef<Subscriptor, T>& operator=(const ConcreteArray3dConstRef<Subscriptor, T>& rhs);
  ConcreteArray3dRef<Subscriptor, T>& operator=(const T& rhs);
protected:
  ConcreteArray3dRef(Subscriptor s, T* p) : Subscriptor(s), datap(p) {}
  friend class ConcreteArray3d<Subscriptor, T>;
private:
  T* const datap;
};

template<class Subscriptor, class T>
class ConcreteArray3d :
  private Subscriptor {
public:
  Subscriptor::dim;
  Subscriptor::shape;
  Subscriptor::numElts;
  Subscriptor::offset;
  Subscriptor::setShape;

  typedef T                                                   EltT;
  typedef Subscriptor                                         SubscriptorT;

  typedef ConcreteArrayProjection2d< Subscriptor, T >         ProjectionT;
  typedef ConstConcreteArrayProjection2d< Subscriptor, T >    ConstProjectionT;

  typedef ConcreteArrayBrowser< ConcreteArray3d<Subscriptor, T> >   BrowserType;
  typedef ConcreteArrayIterator< ConcreteArray3d<Subscriptor, T> >  IteratorType;
  
  const T& operator()(Subscript s0, Subscript s1, Subscript s2) const {
    //    return firstDatum()[offset(SubscriptArray<3>(s0, s1, s2))];
    return firstDatum()[offset(s0, s1, s2)];
  }

  T& operator()(Subscript s0, Subscript s1, Subscript s2) {
    //    return firstDatum()[offset(SubscriptArray<3>(s0, s1, s2))];
    return firstDatum()[offset(s0, s1, s2)];
  }
  
  ConstProjectionT project(Subscript s, Dimension d) const { 
     return ConcreteArray3dConstRef<Subscriptor, T>(*this).project(s, d);
  } 
  ProjectionT project(Subscript s, Dimension d) { 
     return ConcreteArray3dRef<Subscriptor, T>(*this).project(s, d);
  } 
  
  ConstProjectionT operator[](Subscript s) const { return project(s, 0); }
  ProjectionT      operator[](Subscript s)       { return project(s, 0); }

  ConstProjectionT row(Subscript i)    const { return project(i, 0); }
       ProjectionT row(Subscript i)          { return project(i, 0); }
  ConstProjectionT column(Subscript i) const { return project(i, 1); }
       ProjectionT column(Subscript i)       { return project(i, 1); }
  ConstProjectionT plane(Subscript i) const  { return project(i, 2); }
       ProjectionT plane(Subscript i)        { return project(i, 2); }
        
  T const * firstDatum()  const { return datap; }
  T       * firstDatum()        { return datap; }

  Subscriptor subscriptor() const { return *this; }

  ConcreteArray3d<Subscriptor, T>& operator=(const ConcreteArray3dConstRef<Subscriptor, T>& rhs) {
    ConcreteArray3dRef<Subscriptor, T>(*this) = rhs;
    return *this;
  }
  ConcreteArray3d<Subscriptor, T>& operator=(const ConcreteArray3d<Subscriptor, T>& rhs) {
    ConcreteArray3dRef<Subscriptor, T>(*this) = rhs;
    return *this;
  }
  ConcreteArray3d<Subscriptor, T>& operator=(const T& rhs) {
    ConcreteArray3dRef<Subscriptor, T>(*this) = rhs;
    return *this;
  }


  operator ConcreteArray3dConstRef<Subscriptor, T>() const {
    return ConcreteArray3dConstRef<Subscriptor, T>(*this, datap);
  }
  operator ConcreteArray3dRef<Subscriptor, T>() {
    return ConcreteArray3dRef<Subscriptor, T>(*this, datap);
  }
protected:
  ConcreteArray3d(const Subscriptor& s, T* p) : Subscriptor(s), datap(p) {}
  void setSizeOnHeap(Subscript n);
  void reshapeOnHeap(const SubscriptArray<3>& s);
protected:
  T* datap;
};

template<class Subscriptor, class T>
std::ostream& operator<<(std::ostream& os, const ConcreteArray3dConstRef<Subscriptor, T>& a);

template<class Subscriptor, class T>
std::istream& operator>>(std::istream& is, const ConcreteArray3dRef<Subscriptor, T>& a);

template<class Subscriptor, class T>
inline
std::ostream& operator<<(std::ostream& os, const ConcreteArray3d<Subscriptor, T>& a) {
  return os << ConcreteArray3dConstRef<Subscriptor, T>(a);
}

template<class Subscriptor, class T>
inline
std::istream& operator>>(std::istream& is, ConcreteArray3d<Subscriptor, T>& a) {
  return is >> ConcreteArray3dRef<Subscriptor, T>(a);
}

template<class ArrayShape, class AnotherShape, class T>
void concreteCopy(const ConcreteArray3dRef<ArrayShape, T>& lhs, const ConcreteArray3dConstRef<AnotherShape, T >& rhs);

template<class ArrayShape, class AnotherShape, class T>
inline
void concreteCopy(ConcreteArray3d<ArrayShape, T>& lhs, const ConcreteArray3d<AnotherShape, T>& rhs) {
  concreteCopy(ConcreteArray3dRef<ArrayShape, T>(lhs), ConcreteArray3dConstRef<AnotherShape, T>(rhs));
}

template<class ArrayShape, class AnotherShape, class T>
inline
void concreteCopy(ConcreteArray3d<ArrayShape, T>& lhs, const ConcreteArray3dConstRef<AnotherShape, T>& rhs) {
  concreteCopy(ConcreteArray3dRef<ArrayShape, T>(lhs), rhs);
}

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArray3d.c"
#endif

#endif

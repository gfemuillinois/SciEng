/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArray1dH
#define ConcreteArray1dH

class Boolean;
class ostream;

#include "Array/ConcreteArrayIterator.h"
#include "Array/ArrayIterator1d.h"
#include "Array/SubscriptArray.h"

template<class Subscriptor, class T> class ConcreteArray1dRef;
template<class Subscriptor, class T> class ConcreteArray1d;

template<class Subscriptor, class T>
class ConcreteArray1dConstRef :
  private Subscriptor {
public:
  Subscriptor::dim;
  Subscriptor::shape;
  Subscriptor::numElts;
  Subscriptor::offset;

  typedef T           EltT;
  typedef Subscriptor SubscriptorT;
  typedef const T&    ConstProjectionT;
  typedef ArrayBrowser1d< ConcreteArray1dConstRef<Subscriptor, T> >  BrowserType;

  const T&    operator()(Subscript s) const { return firstDatum()[offset(s)]; }                  
  ConstProjectionT operator[](Subscript s) const { return firstDatum()[offset(s)]; }
  
  const T* firstDatum() const { return datap; }

  Subscriptor subscriptor() const { return *this; }
protected:
  ConcreteArray1dConstRef(Subscriptor s, const T* p) : Subscriptor(s), datap(p) {}
  friend ConcreteArray1dRef<Subscriptor, T>;
  friend ConcreteArray1d<Subscriptor, T>;
private:
  void operator=(const ConcreteArray1dConstRef<Subscriptor, T>&);   // Prohibit
private:
  const T* const datap;
};

template<class Subscriptor, class T>
class ConcreteArray1dRef :              
    private Subscriptor {
public:
    Subscriptor::dim;
    Subscriptor::shape;
    Subscriptor::numElts;
    Subscriptor::offset;

    typedef T           EltT;
    typedef Subscriptor SubscriptorT;
    typedef T&          ProjectionT;
    typedef const T&    ConstProjectionT;
    typedef ArrayBrowser1d< ConcreteArray1dRef<Subscriptor, T> >  BrowserType;
    typedef ArrayIterator1d< ConcreteArray1dRef<Subscriptor, T> > IteratorType;

    T&          operator()(Subscript s) const { return firstDatum()[offset(s)]; }                  
    ProjectionT operator[](Subscript s) const { return firstDatum()[offset(s)]; }

    T* firstDatum() const { return datap; }

    Subscriptor subscriptor() const { return *this; }

    operator ConcreteArray1dConstRef<Subscriptor, T>() const;

    ConcreteArray1dRef<Subscriptor, T>& operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs);
    ConcreteArray1dRef<Subscriptor, T>& operator=(const T& rhs);
protected:
    ConcreteArray1dRef(Subscriptor s, T* p) : Subscriptor(s), datap(p) {}
    friend ConcreteArray1d<Subscriptor, T>;
private:
    T* const datap;
};

template<class Subscriptor, class T>
ConcreteArray1dRef<Subscriptor, T>::operator ConcreteArray1dConstRef<Subscriptor, T>() const { 
    return ConcreteArray1dConstRef<Subscriptor, T>(*this, datap);
}

template<class Subscriptor, class T>
class ConcreteArray1d :
    private Subscriptor {
public:
    Subscriptor::dim;
    Subscriptor::shape;
    Subscriptor::numElts;
    Subscriptor::offset;

    typedef T           EltT;
    typedef Subscriptor SubscriptorT;

    typedef T&       ProjectionT;
    typedef const T& ConstProjectionT;

    typedef ConcreteArrayBrowser< ConcreteArray1d<Subscriptor, T> >  BrowserType;
    typedef ConcreteArrayIterator< ConcreteArray1d<Subscriptor, T> > IteratorType;

    T& operator()(Subscript s)       { return firstDatum()[offset(s)]; }
    const T& operator()(Subscript s) const { return firstDatum()[offset(s)]; }

    ProjectionT operator[](Subscript s)       { return firstDatum()[offset(s)]; }
    ConstProjectionT operator[](Subscript s) const { return firstDatum()[offset(s)]; }

    const T * firstDatum() const { return datap; }
    T*        firstDatum()       { return datap; }

    Subscriptor subscriptor() const { return *this; }

    ConcreteArray1d<Subscriptor, T>& operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs) {
    ConcreteArray1dRef<Subscriptor, T>(*this) = rhs;
    return *this;
    }

    ConcreteArray1d<Subscriptor, T>& operator=(ConcreteArray1d<Subscriptor, T> rhs) {
    ConcreteArray1dRef<Subscriptor, T>(*this) = rhs;
    return *this;
    }
    ConcreteArray1d<Subscriptor, T>& operator=(const T& rhs) {
    ConcreteArray1dRef<Subscriptor, T>(*this) = rhs;
    return *this;
    }

    operator ConcreteArray1dConstRef<Subscriptor, T>() const {
    return ConcreteArray1dConstRef<Subscriptor, T>(*this, datap);
    }
    operator ConcreteArray1dRef<Subscriptor, T>() {
    return ConcreteArray1dRef<Subscriptor, T>(*this, datap);
    }

protected:
    ConcreteArray1d(Subscriptor s, T* p) : Subscriptor(s), datap(p) {}
    void setSizeOnHeap(Subscript n);
    void reshapeOnHeap(const SubscriptArray<1>&s);
protected:
    T* datap;
};

template<class Subscriptor, class T>
ostream& operator<<(ostream& os, const ConcreteArray1dConstRef<Subscriptor, T>& a);

template<class Subscriptor, class T>
istream& operator>>(istream& is, ConcreteArray1dRef<Subscriptor, T> a);

template<class Subscriptor, class T>
inline
ostream& operator<<(ostream& os, const ConcreteArray1d<Subscriptor, T>& a) {
  return os << ConcreteArray1dConstRef<Subscriptor, T>(a);
}

template<class Subscriptor, class T>
inline
istream& operator>>(istream& is, ConcreteArray1d<Subscriptor, T>& a) {
  return is >> ConcreteArray1dRef<Subscriptor, T>(a);
}

template<class ArrayShape, class AnotherShape, class T>
void concreteCopy(ConcreteArray1dRef<ArrayShape, T> lhs, ConcreteArray1dConstRef<AnotherShape, T> rhs);

/*
template<class ArrayShape, class T, class AnArray>
void concreteCopy(ConcreteArray1dRef<ArrayShape, T> lhs, const AnArray& rhs);
*/
template<class ArrayShape, class AnotherShape, class T>
inline
void concreteCopy(ConcreteArray1d<ArrayShape, T>& lhs, const ConcreteArray1d<AnotherShape, T>& rhs) {
  concreteCopy(ConcreteArray1dRef<ArrayShape, T>(lhs), ConcreteArray1dConstRef<AnotherShape, T>(rhs));
}

template<class ArrayShape, class AnotherShape, class T>
inline
void concreteCopy(ConcreteArray1d<ArrayShape, T>& lhs, ConcreteArray1dConstRef<AnotherShape, T> rhs) {
  concreteCopy(ConcreteArray1dRef<ArrayShape, T>(lhs), rhs);
}

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArray1d.c"
#endif
      
#endif

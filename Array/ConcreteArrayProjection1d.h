/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArrayProjection1dH
#define ConcreteArrayProjection1dH

#include "Array/ConcreteArray1d.h"

class ostream;
class istream;

template<class Subscriptor, class T>
class ConstConcreteArrayProjection1d :
  public ConcreteArray1dConstRef<Subscriptor::ProjectionT, T> {
public:
  typedef Subscriptor::ProjectionT ProjectionSubscriptor;
  ConstConcreteArrayProjection1d(const ProjectionSubscriptor& s, const T* t) :
     ConcreteArray1dConstRef<ProjectionSubscriptor, T>(s, t) {
  }
protected:
  // Copying a projection does not copy the underlying array elements.  It only duplicates
  // the reference to the underlying array.  We make the copy constructor protected to avoid
  // accidental copies by client code.  Assignment is already prohibited because
  // ConcreteArray1dConstRef's can't be assigned.
  ConstConcreteArrayProjection1d(const ConstConcreteArrayProjection1d<Subscriptor, T>& proj) :
     ConcreteArray1dConstRef<Subscriptor::ProjectionT, T>(proj.subscriptor(), proj.firstDatum()) { 
  }
};


template<class Subscriptor, class T>
class ConcreteArrayProjection1d :                         
    public ConcreteArray1dRef<Subscriptor::ProjectionT, T> {
public:
    typedef Subscriptor::ProjectionT ProjectionSubscriptor;
    ConcreteArrayProjection1d(const ProjectionSubscriptor& s, T* t);

    operator ConstConcreteArrayProjection1d<Subscriptor, T>() const;

    ConcreteArrayProjection1d<Subscriptor, T>& 
        operator=(ConcreteArray1dConstRef<ProjectionSubscriptor, T> rhs);
    ConcreteArrayProjection1d<Subscriptor, T>& 
        operator=(const T& rhs);
protected:
    // Copying a projection does not copy the underlying array elements.  It only duplicates
    // the reference to the underlying array.  We make the copy constructor protected to avoid
    // accidental copies by client code.  
    ConcreteArrayProjection1d(const ConcreteArrayProjection1d<Subscriptor, T>& proj);
};



template<class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>::
ConcreteArrayProjection1d(const ProjectionSubscriptor& s, T* t) : 
    ConcreteArray1dRef<Subscriptor::ProjectionT, T>(s, t) {
}


template<class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>::operator ConstConcreteArrayProjection1d<Subscriptor, T>() const {
    return ConstConcreteArrayProjection1d<Subscriptor, T>(subscriptor(), firstDatum());
}

template<class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>&
ConcreteArrayProjection1d<Subscriptor, T>::operator=(ConcreteArray1dConstRef<ProjectionSubscriptor, T> rhs) {
     ConcreteArray1dRef<ProjectionSubscriptor, T>::operator=(rhs);
     return *this;
}


template<class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>&
ConcreteArrayProjection1d<Subscriptor, T>::operator=(const T& rhs) { 
    ConcreteArray1dRef<ProjectionSubscriptor, T>::operator=(rhs);
    return *this;
}


template<class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>::ConcreteArrayProjection1d(const ConcreteArrayProjection1d<Subscriptor, T>& proj) :
   ConcreteArray1dRef<ProjectionSubscriptor, T>(proj.subscriptor(), proj.firstDatum()) {
}

template<class Subscriptor, class T>
inline
ostream& operator<<(ostream& os, const ConstConcreteArrayProjection1d<Subscriptor, T>& a) {
  return os << ConcreteArray1dConstRef<Subscriptor::ProjectionT, T>(a);
}

template<class Subscriptor, class T>
inline
ostream& operator<<(ostream& os, const ConcreteArrayProjection1d<Subscriptor, T>& a) {
  return os << ConcreteArray1dConstRef<Subscriptor::ProjectionT, T>(a);
}

template<class Subscriptor, class T>
inline
istream& operator<<(istream& is, const ConcreteArrayProjection1d<Subscriptor, T>& a) {
  return is >> ConcreteArray1dRef<Subscriptor::ProjectionT, T>(a);
}

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArrayProjection2dH
#define ConcreteArrayProjection2dH

#include "Array/ConcreteArray2d.h"

#include <iosfwd>

#undef PROTECT_COPY_CONSTRUCTOR
#define PROTECT_COPY_CONSTRUCTOR 0
#if PROTECT_COPY_CONSTRUCTOR
template<class Subscriptor, class T> class ConcreteArray3d;
template<class Subscriptor, class T> class ConcreteArray3dRef;
template<class Subscriptor, class T> class ConcreteArray3dConstRef;
//template<class T, Subscript n0, Subscript n1, Subscript n2> class ConcreteRigidArray3d;
#endif

template<class Subscriptor, class T>
class ConstConcreteArrayProjection2d :
  public ConcreteArray2dConstRef< typename Subscriptor::ProjectionT, T> {
public:
  typedef typename Subscriptor::ProjectionT ProjectionSubscriptor;
  ConstConcreteArrayProjection2d(const ProjectionSubscriptor& s, const T* t) :
     ConcreteArray2dConstRef<ProjectionSubscriptor, T>(s, t) {
  }

#if PROTECT_COPY_CONSTRUCTOR
  // cad: These classes need access to the copy constructor
  friend class ConcreteArray3d< Subscriptor, T >;
  friend class ConcreteArray3dRef< Subscriptor, T >;
  friend class ConcreteArray3dConstRef< Subscriptor, T >;
  template<T, Subscript n0, Subscript n1, Subscript n2> friend class ConcreteRigidArray3d;

  protected:
#endif
  // Copying a projection does not copy the underlying array elements.  It only duplicates
  // the reference to the underlying array.  We make the copy constructor protected to avoid
  // accidental copies by client code.  Assignment is already prohibited because
  // ConcreteArray2dConstRef's can't be assigned.
  ConstConcreteArrayProjection2d(const ConstConcreteArrayProjection2d<Subscriptor, T>& proj) :
    ConcreteArray2dConstRef< typename Subscriptor::ProjectionT, T>(proj.subscriptor(), proj.firstDatum()) { 
  }
};

template<class Subscriptor, class T>
class ConcreteArrayProjection2d :
  public ConcreteArray2dRef< typename Subscriptor::ProjectionT, T> {
public:
  typedef typename Subscriptor::ProjectionT ProjectionSubscriptor;
  ConcreteArrayProjection2d(const ProjectionSubscriptor& s, T* t) :
   ConcreteArray2dRef< typename Subscriptor::ProjectionT, T>(s, t) {
  }

  operator ConstConcreteArrayProjection2d<Subscriptor, T>() const {
    return ConstConcreteArrayProjection2d<Subscriptor, T>(subscriptor(), firstDatum());
  }

  ConcreteArrayProjection2d<Subscriptor, T>& 
     operator=(const ConcreteArray2d<ProjectionSubscriptor, T>& rhs) {
       ConcreteArray2dRef<ProjectionSubscriptor, T>::operator=(rhs);
       return *this;
  }
  ConcreteArrayProjection2d<Subscriptor, T>& 
     operator=(ConcreteArray2dConstRef<ProjectionSubscriptor, T> rhs) {
       ConcreteArray2dRef<ProjectionSubscriptor, T>::operator=(rhs);
       return *this;
  }
  ConcreteArrayProjection2d<Subscriptor, T>& 
     operator=(const T& rhs) {
       ConcreteArray2dRef<ProjectionSubscriptor, T>::operator=(rhs);
       return *this;
  }
  
#if PROTECT_COPY_CONSTRUCTOR
  // cad: These classes need access to the copy constructor
  friend class ConcreteArray3d< Subscriptor, T >;
  friend class ConcreteArray3dRef< Subscriptor, T >;
  friend class ConcreteArray3dConstRef< Subscriptor, T >;
  template<T, Subscript n0, Subscript n1, Subscript n2> 
    friend class ConcreteRigidArray3d;
  
  protected:
#endif
  // Copying a projection does not copy the underlying array elements.  It only duplicates
  // the reference to the underlying array.  We make the copy constructor protected to avoid
  // accidental copies by client code.  
  ConcreteArrayProjection2d(const ConcreteArrayProjection2d<Subscriptor, T>& proj) :
     ConcreteArray2dRef<ProjectionSubscriptor, T>(proj.subscriptor(), proj.firstDatum()) { 
  }
};

template<class Subscriptor, class T>
inline
std::ostream& operator<<(std::ostream& os, const ConstConcreteArrayProjection2d<Subscriptor, T>& a) {
  return os << ConcreteArray2dConstRef< typename Subscriptor::ProjectionT, T>(a);
}

template<class Subscriptor, class T>
inline
std::ostream& operator<<(std::ostream& os, const ConcreteArrayProjection2d<Subscriptor, T>& a) {
  return os << ConcreteArray2dConstRef< typename Subscriptor::ProjectionT, T>(a);
}

template<class Subscriptor, class T>
inline
std::ostream& operator<<(std::istream& is, const ConcreteArrayProjection2d<Subscriptor, T>& a) {
  return is >> ConcreteArray2dRef< typename Subscriptor::ProjectionT, T>(a);
}

#endif

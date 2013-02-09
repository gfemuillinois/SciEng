
#ifndef TEQUALITYH
#define TEQUALITYH

#include "Array/FormedArray1d.h"
#include "SciEng/EquivalentCategory.h"
 
template<class T>
class ComparableFormedArray1d :
    public FormedArray1d<T>,
    public EquivalentCategory< ComparableFormedArray1d<T> > {
public:
    ComparableFormedArray1d(Subscript n);
    ComparableFormedArray1d(const FormedArray1d<T>& f);

  using FormedArray1d<T>::shape;

    // ...
    virtual Array1d<T>& operator=(const ConstArray1d<T>&);
    virtual Array1d<T>& operator=(const T&);

    // User Must Define for EquivalentCategory
    Boolean equivalentTo(const ComparableFormedArray1d<T>&) const;
};


template<class T> 
ComparableFormedArray1d<T>::ComparableFormedArray1d(Subscript n) : FormedArray1d<T>(n){}
template<class T> 
ComparableFormedArray1d<T>::ComparableFormedArray1d(const FormedArray1d<T>& f) : 
FormedArray1d<T>(f){}

template<class T> 
Array1d<T>& ComparableFormedArray1d<T>::operator=(const T& rhs) {
  return FormedArray1d<T>::operator=(rhs);
}

template<class T> 
Array1d<T>& ComparableFormedArray1d<T>::operator=(const ConstArray1d<T>& rhs) {
  return FormedArray1d<T>::operator=(rhs);
}


template<class T>
Boolean ComparableFormedArray1d<T>::equivalentTo(const ComparableFormedArray1d<T>& rhs) const {
    if (shape(0) != rhs.shape(0) ) return Boolean::IsFalse;
    for (Subscript i = shape(0)-1; i >= 0; i--) {
        if ((*this)(i) != rhs(i)) return Boolean::IsFalse;
    }
    return Boolean::IsTrue;
}

#endif

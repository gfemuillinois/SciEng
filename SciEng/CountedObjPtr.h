/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CountedObjPtrH
#define CountedObjPtrH

#include "SciEng/Boolean.h"
#include "SciEng/ReferenceCount.h"

//namespace SciEngLib{

template<class T>
class CountedBuiltInPtr {
public:

    CountedBuiltInPtr() : the_p(0) {}                             // Construct as null pointer
    CountedBuiltInPtr(T* just_newed) : the_p(just_newed) {}       // Construct pointing at heap object
    CountedBuiltInPtr<T>& operator=(const CountedBuiltInPtr<T>&); // Adjust counts
    CountedBuiltInPtr<T>& operator=(T*);                          // Decrease lhs count
    ~CountedBuiltInPtr();                                         // Decrease count, destroy if 0
    Boolean unique() const;                                       // Is count one ?

    T& operator*() const { return *the_p; }                       // Access object
    Boolean isNull() const { return the_p == 0; }


    friend Boolean operator==(const CountedBuiltInPtr<T>& lhs, const CountedBuiltInPtr<T>& rhs) {
        return lhs.the_p == rhs.the_p;
    }
    friend Boolean operator!=(const CountedBuiltInPtr<T>& lhs, const CountedBuiltInPtr<T>& rhs) {
        return lhs.the_p != rhs.the_p;
    }
protected:
    T* the_p;
private:
    ReferenceCount refCount; // Number of pointers to heap object
};



template<class T>
class CountedObjPtr : 
    public CountedBuiltInPtr<T> {
public:
    CountedObjPtr() {}
    CountedObjPtr(T* just_newed) : CountedBuiltInPtr<T>(just_newed) {}
    CountedObjPtr<T>& operator=(T* rhs) {
        CountedBuiltInPtr<T>::operator=(rhs); 
        return *this; 
    }
    CountedObjPtr<T>& operator=(const CountedObjPtr<T>& rhs) { 
        CountedBuiltInPtr<T>::operator=(rhs); 
        return *this; 
    }
    T* operator->() const { return the_p; }

protected:
  using CountedBuiltInPtr<T>::the_p;
};

//}

#ifdef XLC_QNOTEMPINC
#include "SciEng/CountedObjPtr.c"
#endif

#endif


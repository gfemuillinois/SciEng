/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CloneableObjPtrH
#define CloneableObjPtrH

#include "SciEng/Boolean.h"

//namespace SciEngLib{

template<class T>
class CloneableObjPtr {
public:

    CloneableObjPtr(): the_p(0) {}                             // Construct as null pointer
    CloneableObjPtr(T* just_newed): the_p(just_newed) {}       // Construct from new pointer
    ~CloneableObjPtr() { delete the_p; }                       // Discard heap object
    CloneableObjPtr(const CloneableObjPtr<T>&);                // Copy heap object
    CloneableObjPtr(const T& obj) : the_p(obj.clone()) {}      // Copy object
    CloneableObjPtr<T>& operator=(T*);                         // Delete then assign to new pointer.
    CloneableObjPtr<T>& operator=(const CloneableObjPtr<T>&);  // Copy heap object
    T& operator*() const { return *the_p; }                    // Access object
    Boolean isNull() const { return the_p == 0; }               
    T* releaseControl();                                       // Given up lifetime control; no delete.
    T* operator->() const { return the_p; }

    friend Boolean operator==(const CloneableObjPtr<T>& lhs, const CloneableObjPtr<T>& rhs) {
        return lhs.the_p == rhs.the_p;
    }
    friend Boolean operator!=(const CloneableObjPtr<T>& lhs, const CloneableObjPtr<T>& rhs) {
        return lhs.the_p != rhs.the_p;
    }
protected:
    T* the_p;
};

//}

#ifdef XLC_QNOTEMPINC
#include "SciEng/CloneableObjPtr.c"
#endif
#endif


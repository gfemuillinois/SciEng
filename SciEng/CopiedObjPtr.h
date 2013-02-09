/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CopiedObjPtrH
#define CopiedObjPtrH

#include "SciEng/Boolean.h"

//namespace SciEngLib{

template<class T>
class CopiedBuiltInPtr {
public:

    CopiedBuiltInPtr(): the_p(0) {}                              // Construct as null pointer
    CopiedBuiltInPtr(T* just_newed): the_p(just_newed) {}        // Construct from new pointer
    ~CopiedBuiltInPtr() { delete the_p; }                        // Discard heap object
    CopiedBuiltInPtr(const CopiedBuiltInPtr<T>&);                // Copy heap object
    CopiedBuiltInPtr<T>& operator=(T*);                          // Delete then assign to new pointer.
    CopiedBuiltInPtr<T>& operator=(const CopiedBuiltInPtr<T>&);  // Copy heap object
    T& operator*() const { return *the_p; }                      // Access object
    Boolean isNull() const { return the_p == 0; }                
    T* releaseControl();                                         // Given up lifetime control; no delete.

    friend Boolean operator==(const CopiedBuiltInPtr<T>& lhs, const CopiedBuiltInPtr<T>& rhs) {
        return lhs.the_p == rhs.the_p;
    }
    friend Boolean operator!=(const CopiedBuiltInPtr<T>& lhs, const CopiedBuiltInPtr<T>& rhs) {
        return lhs.the_p != rhs.the_p;
    }
protected:
    T* the_p;
};



template<class T>
class CopiedObjPtr : 
    public CopiedBuiltInPtr<T> {
public:
    CopiedObjPtr(const CopiedObjPtr<T>& p) : CopiedBuiltInPtr<T>(p) {}
    CopiedObjPtr() : CopiedBuiltInPtr<T>() {}
    CopiedObjPtr(T* just_newed) : CopiedBuiltInPtr<T>(just_newed) {}
    CopiedObjPtr<T>& operator=(T* rhs) { 
        CopiedBuiltInPtr<T>::operator=(rhs); 
        return *this;
    }
    CopiedObjPtr<T>& operator=(const CopiedObjPtr<T>& rhs) { 
        CopiedBuiltInPtr<T>::operator=(rhs); 
        return *this;
    }
    T* operator->() const { return the_p; }

protected:
  using CopiedBuiltInPtr<T>::the_p;
};

//}

#ifdef XLC_QNOTEMPINC
#include "SciEng/CopiedObjPtr.c"
#endif
#endif


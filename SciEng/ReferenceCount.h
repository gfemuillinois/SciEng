/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ReferenceCountH
#define ReferenceCountH

#include "SciEng/Boolean.h"


class ReferenceCount {             
public:

    ReferenceCount();                                  // Create with count of 1
    ReferenceCount(const ReferenceCount&);             // Copy and increment count
    ReferenceCount& operator=(const ReferenceCount&);  // Assign; decrement lhs count, increment rhs
    ~ReferenceCount();                                 // Decrement count; delete if 0
    Boolean unique() const;                            // True if count is 1
private:
    unsigned int* p_refcnt;                            // Pointer to actual count
    void decrement();                                  // Decrement count; delete if 0

};


inline Boolean ReferenceCount::unique() const { 
  return *p_refcnt == 1; 
}


inline ReferenceCount::ReferenceCount() : p_refcnt(new unsigned int(1)) {}


inline ReferenceCount::ReferenceCount(const ReferenceCount& anRC) :
    p_refcnt(anRC.p_refcnt) { ++*p_refcnt; }


inline void ReferenceCount::decrement() {
    if (unique()) delete p_refcnt;
    else --*p_refcnt;
}

inline ReferenceCount::~ReferenceCount() { decrement(); }


inline ReferenceCount& ReferenceCount::operator=(const ReferenceCount& rhs) {
    ++*rhs.p_refcnt;
    decrement();
    p_refcnt = rhs.p_refcnt;
    return *this;
}


#endif

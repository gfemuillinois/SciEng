/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef OrderedH
#define OrderedH

#include "SciEng/EquivalentCategory.h"


class Ordering {
public:
    enum Relation { less_than = -1, equal_to = 0, greater_than = 1};
};

template<class T>
class Ordered : 
    public EquivalentCategory<T>,
    public Ordering {
public:
    // User Must Define: Ordering::Relation compare(const T&) const;
    Boolean equivalentTo(const Ordered<T>& rhs) const;
    friend Boolean operator< (const Ordered<T>& lhs, const Ordered<T>& rhs);
    friend Boolean operator<=(const Ordered<T>& lhs, const Ordered<T>& rhs); 
    friend Boolean operator>=(const Ordered<T>& lhs, const Ordered<T>& rhs); 
    friend Boolean operator> (const Ordered<T>& lhs, const Ordered<T>& rhs); 
};


template<class T>
inline Boolean Ordered<T>::equivalentTo(const Ordered<T>& rhs) const{
  return ( ((T*) this)->compare((const T&) rhs) == equal_to);
}
       
template<class T>
inline Boolean operator< (const Ordered<T>& lhs, const Ordered<T>& rhs) {
  return ((const T&) lhs).compare((const T&) rhs) == Ordering::less_than;
}

template<class T>
inline Boolean operator<=(const Ordered<T>& lhs, const Ordered<T>& rhs) {
  return ((const T&) lhs).compare((const T&) rhs) <=  Ordering::equal_to;
}

template<class T>
inline Boolean operator>=(const Ordered<T>& lhs, const Ordered<T>& rhs) {
  return ((const T&) lhs).compare((const T&) rhs) >=  Ordering::equal_to;
}

template<class T>
inline Boolean operator> (const Ordered<T>& lhs, const Ordered<T>& rhs) {
  return ((const T&) lhs).compare((const T&) rhs) ==  Ordering::greater_than;
}

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef EquivalentToCategoryH
#define EquivalentToCategoryH

#include "SciEng/Boolean.h"

template<class T1, class T2>
class EquivalentToCategory {
  // This class needed for type restriction
};

template<class T1, class T2>
inline Boolean operator==(const EquivalentToCategory<T1, T2>& lhs, const T2& rhs) {
  return ((const T1&) lhs).equivalentTo((const T2&) rhs);
}

template<class T1, class T2>
inline Boolean operator==(const T2& lhs, const EquivalentToCategory<T1, T2>& rhs) {
  return rhs == lhs;
}

template<class T1, class T2>
inline Boolean operator!=(const EquivalentToCategory<T1, T2>& lhs, const T2& rhs) {
  return ! ( lhs == rhs );
}

template<class T1, class T2>
inline Boolean operator!=(const T2& lhs, const EquivalentToCategory<T1, T2>& rhs) {
  return rhs != lhs;
}

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FieldScalarsCategoryH
#define FieldScalarsCategoryH

#include "Algebra/ExternalScalarsCategory.h"
#include "Algebra/BuiltinInverse.h"


template<class V, class S>
class FieldScalarsCategory :
    public ExternalScalarsCategory<V, S> {
public:
    // User Must Define: V& operator/=(const S& s)
    friend V operator/(const V& v, const S& s) { V temp(v); return temp /= s; }

  // CAD
  // User Must Define: V& operator-=(const S& s)
  // user cand also do  v + (-s) 
  friend V operator-(const V& v, const S& s) { V temp(v); return temp -= s; }

};


#endif

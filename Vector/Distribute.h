/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DistributeH
#define DistributeH

#include "Vector/MisMatchedSizeErr.h"

template<class Op, class Array>
class Distribute1 {
public:
  static Array& over(Array& lhs) {
    for (Array::IteratorType i(lhs); i.more(); i.advance()) Op(i.current());
    return lhs;
  }
};


template<class Op, class Array>
class Distribute2 {             
public:
    static Array& over(Array& lhs, const Array& rhs) { 
        if (lhs.numElts() != rhs.numElts()) throw MisMatchedSizeErr(lhs.numElts(), rhs.numElts());
        Array::IteratorType i(lhs);
        Array::BrowserType j(rhs);
        for (; i.more(); i.advance(), j.advance()) Op(i.current(), j.current());
        return lhs;
    }
};


template<class Op, class Array, class T>
class DistributeS {
public:
  static Array& over(Array& lhs, const T& rhs) {
    for (Array::IteratorType i(lhs); i.more(); i.advance()) Op(i.current(), rhs);
    return lhs;
  }
};

#endif

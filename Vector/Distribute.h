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
    for (typename Array::IteratorType i(lhs); i.more(); i.advance()) Op(i.current());
    return lhs;
  }
};


template<class Op, class Array>
class Distribute2 {             
public:
    static Array& over(Array& lhs, const Array& rhs) { 
        if (lhs.numElts() != rhs.numElts()) throw MisMatchedSizeErr(lhs.numElts(), rhs.numElts());
        typename Array::IteratorType i(lhs);
        typename Array::BrowserType j(rhs);
        for (; i.more(); i.advance(), j.advance()) Op(i.current(), j.current());
        return lhs;
    }
};


template<class Op, class Array, class S>
class DistributeS {
public:
  static Array& over(Array& lhs, const S& rhs) {
    for (typename Array::IteratorType i(lhs); i.more(); i.advance()) Op(i.current(), rhs);
    return lhs;
  }
// CAD
  static Array& over(Array& lhs, const Array& rhs, const S& s) {
    if (lhs.numElts() != rhs.numElts()) 
      throw MisMatchedSizeErr(lhs.numElts(), rhs.numElts());
    typename Array::IteratorType i(lhs);
    typename Array::BrowserType j(rhs);
    for (; i.more(); i.advance(), j.advance()) 
      Op(i.current(), j.current(), s);
    return lhs;
  }

};

// CAD
template<class Op, class Array>
class Distribute3 {             
public:
    static Array& over(Array& lhs, const Array& rhs0, const Array& rhs1) { 
        if (lhs.numElts() != rhs0.numElts()) 
	  throw MisMatchedSizeErr(lhs.numElts(), rhs0.numElts());
        if (lhs.numElts() != rhs1.numElts()) 
	  throw MisMatchedSizeErr(lhs.numElts(), rhs1.numElts());

        typename Array::IteratorType i(lhs);
        typename Array::BrowserType j(rhs0);
        typename Array::BrowserType k(rhs1);
        for (; i.more(); i.advance(), j.advance(), k.advance() ) 
	  Op( i.current(), j.current(), k.current() );

        return lhs;
    }
};


#endif

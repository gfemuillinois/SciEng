/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayIterator1dH
#define ArrayIterator1dH

#include "SciEng/Boolean.h"
#include "SciEng/Subscript.h"

//namespace SciEngLib {

template<class Array>
class ArrayBrowser1d {
public:
  ArrayBrowser1d(const Array& anArray) : a(anArray), s0(0), n0(anArray.shape(0)) {}
  Boolean more() const { return s0 < n0; }
  void    advance()    { s0++; }
  const typename Array::EltT& current() const { return a(s0); }

  ArrayBrowser1d(const Array& array, Subscript sub0, Subscript num0) :
    a(array),
    s0(sub0),
    n0(num0) {
}
private:
  const Array& a;
  Subscript s0;
  const Subscript n0;

};

template<class Array>
class ArrayIterator1d {
public:
  ArrayIterator1d(Array& anArray) : a(anArray), s0(0), n0(anArray.shape(0)) {}
  Boolean more() const { return s0 < n0; }
  void    advance()    { s0++; }
  typename Array::EltT& current() const { return a(s0); }
  operator typename Array::BrowserType() { return Array::BrowserType(a, s0, n0); }
private:
  Array& a;
  Subscript s0;
  const Subscript n0;
};

//}

#endif

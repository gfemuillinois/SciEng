/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayIterator3dH
#define ArrayIterator3dH

#include "SciEng/Boolean.h"
#include "Array/SubscriptArray.h"

class ArrayStepper3d {
public:
  ArrayStepper3d(Subscript shape0, Subscript shape1, Subscript shape2) :
    s0(0), s1(0), s2(0), 
    n0(shape0), n1(shape1), n2(shape2) {}
  Boolean more() const { return s0 < n0; }
  void    advance() { 
    if (++s2 >= n2) { 
      s2 = 0; 
      if (++s1 >= n1) { s1 = 0; s0++; }
    }
  }
protected:
  Subscript s0;
  Subscript s1;
  Subscript s2;
  const Subscript n0;
  const Subscript n1;
  const Subscript n2;
};

template<class Array>
class ArrayBrowser3d :
  public ArrayStepper3d {
public:
  ArrayBrowser3d(const Array& anArray) : 
    ArrayStepper3d(anArray.shape(0), anArray.shape(1), anArray.shape(2)),a(anArray) {}
  const typename Array::EltT& current() const { return a(s0, s1, s2); }

  ArrayBrowser3d(const Array& anArray, const ArrayStepper3d step) :
    ArrayStepper3d(step), a(anArray) {
}
private:
  const Array& a;
};

template<class Array>
class ArrayIterator3d :
  public ArrayStepper3d {
public:
  ArrayIterator3d(Array& anArray) :
    ArrayStepper3d(anArray.shape(0), anArray.shape(1), anArray.shape(2)), a(anArray){}
  typename Array::EltT& current() const { return a(s0, s1, s2); }
  operator typename Array::BrowserType() { return Array::BrowserType(a, *this); }
private:
  Array& a;
};
#endif

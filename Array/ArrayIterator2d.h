/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayIterator2dH
#define ArrayIterator2dH

#include "SciEng/Boolean.h"
#include "Array/SubscriptArray.h"


class ArrayStepper2d {
public:
    ArrayStepper2d(Subscript shape0, Subscript shape1) :
        s0(0), s1(0),
        n0(shape0), n1(shape1) {
    }
    Boolean more() const { return s0 < n0; }
    void advance() {
        if (++s1 >= n1) { s1 = 0; s0++; }
    }
protected:
    Subscript s0;
    Subscript s1;
    const Subscript n0;
    const Subscript n1;
};



template<class Array>
class ArrayBrowser2d :
    public ArrayStepper2d {
public:
    ArrayBrowser2d(const Array& anArray) :
        a(anArray), 
        ArrayStepper2d(anArray.shape(0), anArray.shape(1)) {
    }
    const Array::EltT& current() const { return a(s0, s1); }

    ArrayBrowser2d(const Array& anArray, const ArrayStepper2d& step) :
        a(anArray),
        ArrayStepper2d(step) {
    }
private:
    const Array& a;
};



template<class Array>
class ArrayIterator2d :
    public ArrayStepper2d {
public:
    ArrayIterator2d(Array& anArray) :
        a(anArray), 
        ArrayStepper2d(anArray.shape(0), anArray.shape(1)) {
    }
    Array::EltT& current() const { return a(s0, s1); }
    operator Array::BrowserType() { 
        return Array::BrowserType(a, *this); 
    }
private:
    Array& a;
};


#endif

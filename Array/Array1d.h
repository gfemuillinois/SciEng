/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Array1dH
#define Array1dH

#include "Array/ArrayShape.h"
#include "Array/ArrayIterator1d.h"

#include <iosfwd>

template<class T>
class ConstArray1d :              
    public ArrayShape {
public:
    typedef T EltT;
    typedef ArrayBrowser1d<ConstArray1d<T> > BrowserType;


    virtual const T&          operator()(Subscript i)  const = 0;
    virtual const T&          operator[](Subscript i)  const { return operator()(i); }
    virtual const T&          project(Subscript i)     const { return operator()(i); }
    virtual Dimension         dim()                    const { return 1; }


private:
    void operator=(const ConstArray1d<T>&); // Prohibit
};



template<class T>
class Array1d :              
    public ConstArray1d<T> {
public:
    typedef ArrayIterator1d<Array1d<T> > IteratorType;


    virtual const T& operator()(Subscript i) const = 0;
    virtual       T& operator()(Subscript i)       = 0;
    virtual const T& operator[](Subscript i) const { return operator()(i); }
    virtual       T& operator[](Subscript i)       { return operator()(i); }
    virtual const T& project(Subscript i)    const { return operator()(i); }
    virtual       T& project(Subscript i)          { return operator()(i); }

    virtual Array1d<T>& operator=(const ConstArray1d<T>& rhs);
    virtual Array1d<T>& operator=(const T& rhs);
};


template<class T>
std::istream& operator>>(std::istream& is, Array1d<T>& a);

template<class T>
std::ostream& operator<<(std::ostream& os, const ConstArray1d<T>& a);


#ifdef XLC_QNOTEMPINC
#include "Array/Array1d.c"
#endif

#endif

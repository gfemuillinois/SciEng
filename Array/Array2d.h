/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Array2dH
#define Array2dH

#include "Array/AccessedArray1d.h"
#include "Array/ArrayIterator2d.h"
      

template<class T>
class ConstArray2d :
    public virtual ArrayShape {
public:
    typedef T EltT;


    typedef ArrayBrowser2d< ConstArray2d<T> > BrowserType;
    typedef AccessedConstArray1d<T>           ConstProjectionT;



    virtual const T&         operator()(Subscript i, Subscript j)  const = 0;
    virtual ConstProjectionT project(Subscript i, Dimension d = 0) const = 0;


    virtual Dimension dim() const { return 2; }


    virtual ConstProjectionT operator[](Subscript i) const;
    virtual ConstProjectionT row(Subscript i)        const;
    virtual ConstProjectionT column(Subscript i)     const;


private:
    void operator=(const ConstArray2d<T>&); // Prohibit
};



template<class T>
class Array2d : 
    public virtual ConstArray2d<T> {
public:

    typedef ArrayIterator2d< Array2d<T> > IteratorType;
    typedef AccessedArray1d<T>            ProjectionT;



    virtual const T&         operator()(Subscript i, Subscript j)  const = 0;
    virtual T&               operator()(Subscript i, Subscript j)        = 0;
    virtual ProjectionT      project(Subscript i, Dimension d = 0)       = 0;
    virtual ConstProjectionT project(Subscript i, Dimension d = 0) const = 0;



    virtual ConstProjectionT operator[](Subscript i) const;
    virtual      ProjectionT operator[](Subscript i);
    virtual ConstProjectionT row(Subscript i)        const;
    virtual      ProjectionT row(Subscript i);
    virtual ConstProjectionT column(Subscript i)     const;
    virtual      ProjectionT column(Subscript i);


    virtual Array2d<T>& operator=(const ConstArray2d<T>& rhs);
    virtual Array2d<T>& operator=(const T& rhs);
};


template<class T>
istream& operator>>(istream& is, Array2d<T>& a);

template<class T>
ostream& operator<<(ostream& os, const ConstArray2d<T>& a);

#ifdef XLC_QNOTEMPINC
#include "Array/Array2d.c"
#endif

#endif

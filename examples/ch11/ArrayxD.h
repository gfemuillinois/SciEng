/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#ifndef ARRAYXDHPP
#define ARRAYXDHPP

#include "Array/ArrayShape.h"

// WARNING: A modified copy of Array2d is in the file average.C.
// Be sure to keep the two files consistent.



template<class T>
class Array1d :
    public virtual ArrayShape {
public:

    virtual Array1d<T>& operator=(const Array1d<T>& rhs)       = 0;
    virtual Array1d<T>& operator=(const T& rhs)                = 0;

    virtual const T&    operator()(Subscript i)          const = 0;
    virtual T&          operator()(Subscript i)                = 0;

};

template<class T>
class Array2d :
    public virtual ArrayShape {
public:

    virtual Array2d<T>& operator=(const Array2d<T>& rhs)           = 0;
    virtual Array2d<T>& operator=(const T& rhs)                    = 0;

    virtual const T&    operator()(Subscript i, Subscript j) const = 0;
    virtual T&          operator()(Subscript i, Subscript j)       = 0;

};


#endif

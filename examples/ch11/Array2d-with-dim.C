/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayShape.h"


template<Dimension ndim>
class DimensionedArrayShape :
    public virtual ArrayShape {
public:
    virtual Dimension dim() const { return ndim; }
};



template<class T>
class Array2d :
    public virtual ArrayShape,
    private DimensionedArrayShape<2> {
public:
    // ...
};


void f() {
  Array2d<int>* p = 0;
}

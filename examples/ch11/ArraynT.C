/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayShape.h"


template<Dimension ndim, class T>
class Array :
    public virtual ArrayShape {
public:
    virtual Array<ndim, T>& operator=(const Array<ndim, T>& rhs) = 0;
    virtual Array<ndim, T>& operator=(const T& rhs) = 0;

    // virtual T& operator[]( ??? );  // Subscripting ??
    // ...
};


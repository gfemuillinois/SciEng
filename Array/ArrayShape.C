/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayShape.h"
#include "SciEng/Boolean.h"

ArrayShape::~ArrayShape() {}


Subscript ArrayShape::numElts() const { 
    Dimension d = dim() - 1;
    Subscript n = shape(d);
    while (d > 0) n *= shape(--d);
    return n;
    }


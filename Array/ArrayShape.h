/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayShapeH
#define ArrayShapeH

#include "SciEng/Subscript.h"
#include "SciEng/SciEngErr.h"

class ostream;


class ArrayShape {		
public:

    virtual Dimension dim()              const = 0;
    virtual Subscript shape(Dimension d) const = 0;
    virtual Subscript numElts()          const;


    virtual ~ArrayShape();
};


#endif


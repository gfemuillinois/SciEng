/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/CopiedObjPtr.h"
#include "examples/ch6/Circle.h"


class CopiedCirclePtr : 
    public CopiedObjPtr<Circle> {
public:
    CopiedCirclePtr(double radius) : 
        CopiedObjPtr<Circle>( new Circle(radius) ) {}
    CopiedCirclePtr(Point center, double radius) : 
        CopiedObjPtr<Circle>( new Circle(center, radius) ) {}
    CopiedCirclePtr(Point p1, Point p2, Point p3) :
        CopiedObjPtr<Circle>( new Circle(p1, p2, p3) ) {}
    CopiedCirclePtr(LineSegment chord, Point p) :
        CopiedObjPtr<Circle>( new Circle(chord, p) ) {}
    CopiedCirclePtr(LineSegment diameter) :
        CopiedObjPtr<Circle>( new Circle(diameter) ) {}
};



CopiedCirclePtr c1_p(10.1);
CopiedCirclePtr c2_p(Point(0, 1), 3.5);


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CircleH
#define CircleH

#include "examples/ch6/Point.h"

class LineSegment {
public:
  LineSegment(Point, Point);
  Point midPoint() const;
  double length() const;
};


class Circle {
public:

    Circle(double radius);                // Of specified radius centered at origin
    Circle(Point center, double radius);  // From center and radius
    Circle(Point p1, Point p2, Point p3); // From three points on circle
    Circle(LineSegment chord, Point p);   // From chord and point on circle
    Circle(LineSegment diameter);         // From diameter
    // ...

private:

    Point  the_center;
    double the_radius;

};

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch6/Circle.h"


Circle::Circle(double radius) :
    the_center(0, 0),
    the_radius(radius) {
}

Circle::Circle(Point center, double radius) :
    the_center(center),
    the_radius(radius) {
}


Circle::Circle(LineSegment diameter) :
    the_center(diameter.midPoint()),
    the_radius(.5 * diameter.length()) {
}

extern Point centerOfCircleThrough(Point, Point, Point);

Circle::Circle(Point p1, Point p2, Point p3) :
    the_center(centerOfCircleThrough(p1, p2, p3)),
    the_radius(the_center.distance(p1)) {
}


void f() {


Point       p1(3, 4);        // Create Point p1 initialized to (3, 4)
Point       p2(5, 6);        // Create Point p2 initialized to (5, 6)
Point       p3(7, 8);        // Create Point p3 initialized to (7, 8)
LineSegment l1(p1, p2);      // Create LineSegment l1 with endpoints p1 & p2
Circle      ca(l1, p3);      // Create Circle with chord l1 through point p3
Circle      cb(l1);          // Create Circle with diameter l1
Circle      cc(p1, p2, p3);  // Create Circle through p1, p2, & p3




  Circle c1(Point(1, 2), 10); // No copy
  Circle c2(c1);              // c2 initialized by copying c1
  Circle c3 = 10.0;           // Create Circle(10.0) then initialize c3 from it


}

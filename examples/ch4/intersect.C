/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "examples/ch4/Point.h"
#include "examples/ch4/Line.h"

int main() {


Line l1(Point(0,0), Point(0,1));   // Vertical line through origin
Line l2(Point(1,2), 1, 1);         // Line through (1,2) in direction <1,1>


Point intersection;
intersection = l1.intersect(l2);
cout << "(" << intersection.x() << "," << intersection.y() << ")" << endl;


Line l3(Point(0,0), .005, 1);
Point inter_parallel = l1.intersect(l3);
cout << "(" << inter_parallel.x() << "," << inter_parallel.y() << ")" << endl;


Line::parallelism_tolerance = .02618;  // 1.5 degrees (in radians)


Point inter_parallel2 = l1.intersect(l3);
cout << "(" << inter_parallel2.x() << "," << inter_parallel2.y() << ")" << endl;

return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include <float.h>
#include "examples/ch4/Point.h"
#include "examples/ch4/Line.h"


Line::Line(Point p1, Point p2) {
    // Construct a Line through points p1 and p2.

    if (p1.x() == p2.x()) {  // Vertical line

        a = 1; 
        b = 0; 
        c = -p1.x();
    }

    else {                   // Nonvertical line


        a = p2.y() - p1.y();
        b = p1.x() - p2.x();
        c = p1.y() * p2.x() - p2.y() * p1.x();

    }
}
 
Line::Line(Point p, Number xDir, Number yDir) {
    // Construct a Line through p with tangent <xDir, yDir>.

    a = yDir;
    b = -xDir;
    c = xDir * p.y() - yDir * p.x();

}
 
Number Line::distance(Point point) {
    // Returns the distance from point to the line.
    return fabs( a * point.x() + b * point.y() + c ) / sqrt(a*a + b*b);
}



Point Line::intersect(Line line) {
    // Intersect with line.  If the angle between the two lines is less than
    // the parallelism_tolerance, return the point at infinity.  The parallelism
    // test computes the square of the sin of the angle.  We assume that the
    // tolerance is small enough for sin(theta) to be approximately equal to theta.
    Number det = a * line.b - line.a * b;
    Number sinsq = (det * det) / ( (a*a + b*b) * (line.a*line.a + line.b*line.b) );
    if (sinsq < parallelism_tolerance * parallelism_tolerance) {
        return Point(FLT_MAX, FLT_MAX); // Point at infinity (FLT_MAX from float.h)
    }
    else {
        return Point( (b * line.c - line.b * c) / det, (c * line.a - line.c * a) / det ); 
    }
}



Number Line::parallelism_tolerance = .01745; // 1 degree (in radians)


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include "examples/ch4/Point.h"
#include "examples/ch4/Line.h"


Point::Point(Number x, Number y) {

    the_x = x;
    the_y = y;

}

Point::Point() {
}




Number Point::x() { return the_x; }
Number Point::y() { return the_y; }




Number Point::distance(Point point) {
    Number x_dif = the_x - point.the_x;
    Number y_dif = the_y - point.the_y;
    return sqrt(x_dif * x_dif  +  y_dif * y_dif);
}



Number Point::distance(Line line) { return line.distance(*this); }


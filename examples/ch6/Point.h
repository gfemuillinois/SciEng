/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <math.h>
typedef float Number;

class Line;


class Point {
public:

    Point();                              // Create uninitialized
    Point(Number x, Number y);            // Create from (x,y)
    Number distance(Point point) const;   // Distance to another point
    Number distance(Line line) const;     // Distance to a line
    Number& x();                          // Reference to x-coordinate
    Number x() const;                     // Get x-coordinate
    Number& y();                          // Reference to y-coordinate
    Number y() const;                     // Get y-coordinate
    Number angle(Point p1, Point p3) const;
private:
    Number the_x;                         // x-coordinate
    Number the_y;                         // y-coordinate
};



inline Point::Point() {}
inline Point::Point(Number x, Number y) : the_x(x), the_y(y) {}
inline Number& Point::x()       { return the_x; }
inline Number& Point::y()       { return the_y; }
inline Number  Point::x() const { return the_x; }
inline Number  Point::y() const { return the_y; }

inline
istream& operator>>(istream& is, Point& p) {
  return is >> p.x() >> p.y();
}

inline
ostream& operator<<(ostream& os, const Point& p) {
  return os << "(" << p.x() << "," << p.y() << ")";
}

inline
Number Point::angle(Point p1, Point p3) const {
  Number v21[2] = { p1.x() - x(), p1.y() - y() };
  Number v23[2] = { p3.x() - x(), p3.y() - y() };
  Number dot_product = v21[0] * v23[0] + v21[1] * v23[1];
  Number cross_product = v23[0] * v21[1] - v23[1] * v21[0];
  Number ang = atan2(cross_product, dot_product);
  if (ang < 0) ang += 2.0 * M_PI;
  return ang;
}

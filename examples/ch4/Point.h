/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

typedef float Number;

class Line;

class Point {
public:

    Point();                     // Create uninitialized
    Point(Number x, Number y);   // Create from (x,y)
    Number distance(Point point);// Distance to another point
    Number distance(Line line);  // Distance to a line
    Number x();                  // Get x-coordinate
    Number y();                  // Get y-coordinate
private:
    Number the_x;                // x-coordinate
    Number the_y;                // y-coordinate
};



/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class Line {
public:

    Line(Point p1, Point p2);                // Line through two points
    Line(Point p, Number xDir, Number yDir); // Line through p with tangent <xDir, yDir>
    Point intersect(Line line);              // Intersection with line
    Number distance(Point point);            // Distance to a point

    static Number parallelism_tolerance;     // Smallest nonparallel angle (radians) 

private:
    // ax + by + c = 0
    Number a;
    Number b;
    Number c;
};



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
 
int main() {
    // Read the coordinates of a point and print the distance
    // from the origin to the point.
    Point origin(0, 0);

    Number x; 
    Number y; 
    cin >> x >> y;
    Point p(x, y);

    cout << origin.distance(p) << endl;
    return 0;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream>
#include "examples/ch4/Point.h"
using std::cout;
using std::cin;
using std::endl;
 
int main() {
    // Read coordinates of a point and compute its distance to the origin
    Point origin;
    float x; cin >> x;
    float y; cin >> y;
    Point p(x, y);
    cout << origin.distance(p) << endl;
    return 0;
}


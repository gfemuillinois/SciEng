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

#include <math.h>
 
int main() {

  cout << "\nRead the coordinates of a point in 2-D and\n"
    "print the distance from the origin to the point." << endl;

    Point origin(0, 0);

    Number x; 
    Number y; 
    cout << "x y = ";
    cin >> x >> y;
    Point p(x, y);

    cout << origin.distance(p) << endl;

    cout << " fabs(x) = " << fabs(x) << endl;

    return 0;
}


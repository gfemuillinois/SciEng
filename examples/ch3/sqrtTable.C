/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int main() {

float x;
while (cin >> x && x >= 0.) {
    cout << setw(25) << x << setw(25) << sqrt(x) << endl;
}

return 0;
}

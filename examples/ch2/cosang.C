/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

// Read an angle in degrees and print its cosine.
#include <iostream>
#include <math.h>

int main() {

    float angle;                                  // Angle, in degrees
    std::cin >> angle;
    std::cout << cos(angle * M_PI / 180.0 ) << std::endl;   // M_PI is from <math.h>
    return 0;
}



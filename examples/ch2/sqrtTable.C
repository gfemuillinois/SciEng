/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <iomanip>
#include <math.h>

int main() {

float x;
while (std::cin >> x) {
    std::cout << std::setw(25) << x << std::setw(25) << sqrt(x) << std::endl;
}

return 0;
}

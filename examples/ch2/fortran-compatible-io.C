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

int main() {
    double a = 3.14159;
    double b = 1 / a;
    double c = 10 * a;

    // Use FORTRAN compatibility output.
    std::cout << setiosflags(std::ios::showpoint | std::ios::uppercase);

    // Write data in G15.8 format.
    std::cout << std::setw(15) << std::setprecision(8) << a;
    std::cout << std::setw(15) << std::setprecision(8) << b;

    // Write in F10.3 format
    std::cout << setiosflags(std::ios::fixed);
    std::cout << std::setw(10) << std::setprecision(3) << c << std::endl;

    return 0;
}


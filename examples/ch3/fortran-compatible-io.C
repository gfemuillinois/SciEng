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
using std::cout;
using std::cin;
using std::endl;

int main() {
    double a = 3.14159;
    double b = 1 / a;
    double c = 10 * a;

    // Use FORTRAN compatibility output.
    cout << setiosflags(std::ios::showpoint | std::ios::uppercase);

    // Write data in G15.8 format.
    cout << std::setw(15) << std::setprecision(8) << a;
    cout << std::setw(15) << std::setprecision(8) << b;

    // Write in F10.3 format
    cout << std::setiosflags(std::ios::fixed);
    cout << std::setw(10) << std::setprecision(3) << c << endl;

    return 0;
}


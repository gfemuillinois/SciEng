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

int main() {
    double a = 3.14159;
    double b = 1 / a;
    double c = 10 * a;

    // Use FORTRAN compatibility output.
    cout << setiosflags(ios::showpoint | ios::uppercase);

    // Write data in G15.8 format.
    cout << setw(15) << setprecision(8) << a;
    cout << setw(15) << setprecision(8) << b;

    // Write in F10.3 format
    cout << setiosflags(ios::fixed);
    cout << setw(10) << setprecision(3) << c << endl;

    return 0;
}


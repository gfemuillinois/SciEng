/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream.h>

int main() {
    // Read the coefficients of a line equation in the form ax+by+c = 0,
    // then print the line's x- and y-intercepts.

    // Read the equation coefficients.
    float a, b, c;
    cin >> a >> b >> c;

    // Print the equation coefficients.
    cout << "Coefficients: " << a << ", " << b << ", " << c << endl;

    // Compute and print the x-intercept.
    cout << "x-intercept: ";
    if (a != 0) {
        cout << -c / a << ", ";
    } 
    else {
        cout << "none, ";
    }


    // Compute and print the y-intercept.
    cout << "y-intercept: ";
    if (b != 0) {
        cout << -c / b << endl;
    } 
    else {
        cout << "none" << endl;
    }

    return 0;
} 


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream>

int main() {
    // Read the coefficients of a line equation in the form ax+by+c = 0,
    // then print the line's x- and y-intercepts.

    // Read the equation coefficients.
    float a, b, c;
    std::cin >> a >> b >> c;

    // Print the equation coefficients.
    std::cout << "Coefficients: " << a << ", " << b << ", " << c << std::endl;

    // Compute and print the x-intercept.
    std::cout << "x-intercept: ";
    if (a != 0) {
        std::cout << -c / a << ", ";
    } 
    else {
        std::cout << "none, ";
    }


    // Compute and print the y-intercept.
    std::cout << "y-intercept: ";
    if (b != 0) {
        std::cout << -c / b << std::endl;
    } 
    else {
        std::cout << "none" << std::endl;
    }

    return 0;
} 


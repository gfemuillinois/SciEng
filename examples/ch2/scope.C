/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <stdlib.h>


void f() {
    float temp = 1.1;
    int a;
    int b;
    std::cin >> a >> b;

    if (a < b) {
        int temp = a;  // This "temp" hides the one in function scope.
        std::cout << 2 * temp << std::endl;
    }// Block ends; local "temp" deleted.
    else {
        int temp = b;  // Another "temp" hides the one in function scope.
        std::cout << 3 * temp << std::endl;
    }

    std::cout << a * b + temp << std::endl;
}


int main() {
  f();
  f();
  return EXIT_SUCCESS;
}

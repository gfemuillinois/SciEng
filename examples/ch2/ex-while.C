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
    int i = 13;
    while (i) {
        i /= 2;
        std::cout << i << std::endl;
    }
    return 0;
}


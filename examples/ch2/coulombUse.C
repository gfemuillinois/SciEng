/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream>
#include "examples/ch2/coulombsLaw.h"
 
int main() {
    std::cout << coulombsLaw(1.6e-19, 1.6e-19, 5.3e-11) << " newtons" << std::endl;
    return 0;
}


void foo() {

std::cout << coulombsLaw(1.6e-19, 1.6e-19, 1) << " newtons" << std::endl;

}

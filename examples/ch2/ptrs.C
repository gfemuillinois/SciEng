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

int* p;


int i = 3;
p = &i;


int j = 4;
p = &j;


std::cout << *p << std::endl;


*p = 5;
std::cout << *p << " " << i << " " << j << std::endl;


if (p != 0) {
    std::cout << "Pointer p points at " << *p << std::endl;
} 

return 0;
}

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


int i = 1;
std::cout << i << ", ";         // Print i
std::cout << (++i) << ", ";     // Increment i, then print its new value
std::cout << i << ", ";         // Print i
std::cout << (i++) << ", ";     // Print i's old value, then increment i
std::cout << i << std::endl;    // Print i


return 0;   
}

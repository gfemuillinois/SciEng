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

char command;
enum commandFlags {enable = 0x01, pulse = 0x02, tone = 0x04, reset = 0x08 };
command = (enable | tone);

std::cout.setf(std::ios::showbase);
std::cout.setf(std::ios::hex, std::ios::basefield);
std::cout << int(command) << std::endl;
return 0;
}


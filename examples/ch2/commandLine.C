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
#include <getopt.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    std::cout << "Flags found: ";
    int flag;
    while ((flag = getopt(argc, argv, "abcdefg")) != EOF) {
        char flagc = flag;
        std::cout << flagc << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}


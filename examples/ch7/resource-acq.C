/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <fstream>

static int data_is_bad = 0;
class BadData {};


void process_file(const char* in_name, const char* out_name) {
    std::ifstream in_file(in_name);
    std::ofstream out_file(out_name);

    // Process input file, generating output file
    // ...
    if (data_is_bad) throw BadData();
    // ...
}


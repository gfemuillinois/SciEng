/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <fstream.h>

static int data_is_bad = 0;
class BadData {};


void process_file(const char* in_name, const char* out_name) {
    ifstream in_file(in_name);
    ofstream out_file(out_name);

    // Process input file, generating output file
    // ...
    if (data_is_bad) throw BadData();
    // ...
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch7/TraceLifetime.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int  TraceLifetime::total_created = 0;
char TraceLifetime::existing_objects[1+TraceLifetime::max_objects_to_trace] = "";


TraceLifetime::TraceLifetime(const char* variable_name) : 
    instance_number(total_created++) {
    // Copy first 20 characters of variable name
    strncpy(var_name, variable_name, 20);
    var_name[20] = '\0';

    if (total_created <= max_objects_to_trace) {

        existing_objects[total_created-1] = 'L';
        existing_objects[total_created]   = '\0';

        cout << existing_objects << " TraceLifetime constructed for " << var_name << "." << endl;
    }
}
 
TraceLifetime::~TraceLifetime() {
    if (instance_number < max_objects_to_trace) {
        existing_objects[instance_number] = 'D';
        cout << existing_objects << " TraceLifetime destroyed for " << var_name << "." << endl;
    }
}


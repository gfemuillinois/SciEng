/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef TraceLifetimeH
#define TraceLifetimeH


class TraceLifetime {
public:

    TraceLifetime(const char* variable_name);              // Create and print message.
    ~TraceLifetime();                                      // Destroy and print message.
private:
    enum { max_objects_to_trace = 100 };                   // Maximum number of objects to trace
    static char existing_objects[1+max_objects_to_trace];  // L = live; D = destroyed.
    static int total_created;
    int instance_number;                                   // Creation sequence number.
    char var_name[21];                                     // Name of variable (first 20 chars + null)
    // This should be String, but I get an internal compiler error message when using String

};

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SciEngEnvironmentH
#define SciEngEnvironmentH

#include "SciEng/SciEngErr.h"
#include "SciEng/String.h"
#include "SciEng/Terminate.h"
#include "SciEng/NewHandler.h"


class SciEngStartup {
public:
    SciEngStartup();
private:
    static NewHandler nh;
    static Terminate  th;
};

static SciEngStartup initialize_SciEngErr;


extern void userErrMessage(const SciEngErr& e);  // Print message to cerr


class FinalErr : 
    public SciEngErr {
public:
    virtual String message() const;
};

class OutOfMemoryErr : 
    public SciEngErr {
public:
    virtual String message() const;
private:
    static String out_of_memory_message;
};
#endif

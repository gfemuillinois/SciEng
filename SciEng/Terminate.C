/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <stdlib.h>
#include "SciEng/Terminate.h"
#include "SciEng/SciEngEnvironment.h"

// This is the default terminate handler set up by SciEngEnvironment.
// It gets called when an exception is thrown for which there is no
// catch.  The default handler calls "rethrow", which re-throws the
// original exception (even though it doesn't know what the original
// exception was).  If the original exception was one of ours, we catch
// it, print out the error message, and go away.  If the original exception
// was not one of ours, about the only thing we can do is to print a
// message and go home.

static void rethrow() { throw; }

void Terminate::defaultHandler() { 
    try { 
        rethrow();
    }
    catch(const SciEngErr& e) { 
        userErrMessage(e);
    }
    catch(...) { 
        FinalErr its_over;
        userErrMessage(its_over);
        exit(EXIT_FAILURE);
    }
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/Fallible.h"
#include "SciEng/String.h"


String FallibleBase::UsedInInvalidStateErr::message() const {
    return "Fallible object used in invalid state.";
}

void FallibleBase::throwErr() const {
    throw FallibleBase::UsedInInvalidStateErr();
}


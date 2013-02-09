/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Function/Function.h"
#include "SciEng/SciEngString.h"

String UnsetPtrErr::message() const {
  return "Attempt to call a Function whose pointer was not set";
}


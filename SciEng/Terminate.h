/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef TerminateH
#define TerminateH

//#include <terminate.h>
#include <exception>

#include "SciEng/HandlerStack.h"

//namespace SciEngLib{

typedef HandlerStack<std::set_terminate> Terminate;


//}
#endif


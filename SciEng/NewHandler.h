/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NewHandlerH
#define NewHandlerH

#include <new>
#include "SciEng/HandlerStack.h"

//namespace SciEngLib{

typedef HandlerStack<std::set_new_handler> NewHandler;

//}

#endif


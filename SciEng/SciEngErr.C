/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "SciEng/SciEngErr.h"
#include "SciEng/String.h"

//namespace SciEngLib{

std::ostream& operator<<(std::ostream& s, const SciEngErr& e) { 
    return s << e.message();
}


SciEngErr::~SciEngErr() {}

//}

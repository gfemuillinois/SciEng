/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SciEngErrH
#define SciEngErrH

#include <iosfwd>

//namespace SciEngLib{

class String;

class SciEngErr {
public:                             
    virtual String message() const = 0;
    virtual ~SciEngErr();             
};

std::ostream& operator<<(std::ostream& s, const SciEngErr& e);

//}
#endif


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MappingBrowserDomainErrH
#define MappingBrowserDomainErrH

#include "SciEng/SciEngErr.h"

class MappingBrowserDomainErr : 
    public SciEngErr {
public:
    virtual String message() const;
};

#include "SciEng/String.h"

String MappingBrowserDomainErr::message() const {
  return "MappingBrowser::DomainErr: operator() called when domain.more() false.";
}

#endif

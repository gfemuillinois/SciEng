/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SubDomainH
#define SubDomainH

#include "SciEng/SciEngErr.h"
#include "SciEng/SciEngString.h"


template<class Domain>
class SubDomainErr : 
    public SciEngErr {
public:
    SubDomainErr(const Domain& x, const String& msg) : err_message(msg), bad_value(x)  {}
    virtual String message() const;
private:
    const String err_message;
    Domain bad_value;
};



template<class Domain, class Predicate>
class SubDomain {    
public:
    SubDomain(const Domain& x) : 
        value(x) {
        if ( !Predicate::isSatisfied(x) ) throw SubDomainErr<Domain>(value, Predicate::description());
    }

    operator Domain() const  { return value; }

private:
    Domain value;
};


#ifdef XLC_QNOTEMPINC
#include "Algebra/SubDomain.c"
#endif

#endif

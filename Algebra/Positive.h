/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef PositiveH
#define PositiveH

#include "Algebra/SubDomain.h"
#include "SciEng/Boolean.h"


template<class T>
class PositivePredicate { 
public:

    static Boolean isSatisfied(const T& x) { return x > 0; }
    static String  description()           { return "is not positive"; }

};



template<class T>
class Positive :  
    public SubDomain<T, PositivePredicate<T> > { 
public:
    Positive(const T& x) : SubDomain<T, PositivePredicate<T> >(x) {}
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ArrayErrH
#define ArrayErrH

#include "SciEng/SciEngErr.h"


class ArrayErr {
public:
    class Dimensionality : public SciEngErr {
    public:
        virtual String message() const;
    };

    class Shape : public SciEngErr {
    public:
        virtual String message() const;
    };

    class CreationSize : public SciEngErr {
    public:
        virtual String message() const;
    };

    class NegativeSize : public SciEngErr {
    public:
        virtual String message() const;
    };

    class Symmetry : public SciEngErr {
    public:
        virtual String message() const;
    };

    class SubscriptRange : public SciEngErr {
    public:
        virtual String message() const;
    };
};


#endif


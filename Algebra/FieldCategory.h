/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FieldCategoryH
#define FieldCategoryH

#include "Algebra/AbelianGroupCategory.h"
#include "Algebra/GroupCategory.h"


template<class T>
class FieldCategory : 
    public AbelianGroupCategory<T>, 
    public GroupCategory<T> {

        T& operator++()     { T one((T&)*this); one.setToOne(); return (T&)*this += one; }
        T  operator++(int)  { T orig((T&)*this); ++*this; return orig;                   }
        T& operator--()     { T one((T&)*this); one.setToOne(); return (T&)*this -= one; }
        T  operator--(int)  { T orig((T&)*this); --*this; return orig;                   }

    };


    #endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef IteratedEquationsH
#define IteratedEquationsH

#include "SciEng/Boolean.h"
#include "Array/Array1d.h"


template<class T>
class IteratedEquations {  
public:

    virtual T       update(Array1d<T>& a)       = 0;  // Returns norm of update vector.
    virtual Boolean converged()           const = 0;
    virtual         ~IteratedEquations()        {}

};

       
#endif

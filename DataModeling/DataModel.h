/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DataModelH
#define DataModelH

#include "Function/Functional.h"
#include "AutoDeriv/TaylorCoefficient1d.h"

// An interface to {y(x_i; \vec{a}), grad(y)_a}, a function from coordinates to values+gradients
//    with model variables as parameters in the function.

template<class T>
class DataModel :            
    public virtual Functional< T, TaylorCoefficient1d<T> > {
public:

    virtual       Array1d<T>& parameters()       = 0;
    virtual const Array1d<T>& parameters() const = 0;

};


#endif

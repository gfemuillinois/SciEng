/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidRall1dH
#define RigidRall1dH

#include "AutoDeriv/Rall1d.h"
#include "Vector/RigidArithmetic.h"

/* RigidRall1ds are Rall numbers with RigidArithmetic1d gradient vectors */

template<class T, Subscript nvars>
class RigidRall1d : 
    public Rall1d<T, RigidArithmetic1d<T,nvars> > {
public:

    // constants
    RigidRall1d() :           Rall1d<T, RigidArithmetic1d<T,nvars> >(0.0, nvars)  {}       
    RigidRall1d(const T& c) : Rall1d<T, RigidArithmetic1d<T,nvars> >(c, nvars)    {}

    // variables
    RigidRall1d(const T& v, int i_th, int n = nvars) : 
        Rall1d<T, RigidArithmetic1d<T,nvars> >(v, i_th, nvars) {
    }

    RigidRall1d(const Rall1d<T, RigidArithmetic1d<T, nvars> >& r): 
        Rall1d<T, RigidArithmetic1d<T, nvars> >(r) { 
    }
};

#endif

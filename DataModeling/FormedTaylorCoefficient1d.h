/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedTaylorCoefficient1dH
#define FormedTaylorCoefficient1dH

#include "Array/FormedArray.h"
#include "AutoDeriv/TaylorCoefficient1d.h"


template<class T>
class FormedTaylorCoefficient1d :  
    public virtual TaylorCoefficient1d<T> {
public:
    FormedTaylorCoefficient1d(Subscript max_power = 0) : 
        fa(max_power) {
    }
    FormedTaylorCoefficient1d(const TaylorCoefficient1d<T>& t) : 
        fa(t.gradient()),
        the_value(t.value()) {
    }


    virtual const T&  value() const { return the_value; }
    virtual T&        value() { return the_value; }

private:
    virtual const Array1d<T>& doGradient() const { return fa; }
    FormedArray1d<T> fa;
    T the_value;
};


//  private PtrWrappers1d< FormedTaylorCoefficient1d<T>, TaylorCoefficient1d<T> > {
#endif

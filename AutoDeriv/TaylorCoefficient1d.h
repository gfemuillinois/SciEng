/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef TaylorCoefficient1dH
#define TaylorCoefficient1dH
 
#include "Array/Array1d.h"
           

template<class T>
class TaylorCoefficient1d :   
    public virtual Array1d<T>,    // Gradients
    private FormedArray1d<T> {
public:
    TaylorCoefficient1d(const T& value, Subscript n_grads);
    TaylorCoefficient1d(const T& value, const ConstArray1d<T>& gradients);


    const T& value() const { return the_value; }
    T&       value()       { return the_value; }


    // Access declarations and assignment operators ... not shown
private:
    typedef FormedArray1d<T> Impl;
public:
    Impl::shape;
    Impl::dim;
    Impl::numElts;
    Impl::operator();

    virtual Array1d<EltT>& operator=(const ConstArray1d<EltT>& rhs) { return Impl::operator=(rhs); }
    virtual Array1d<EltT>& operator=(const EltT& rhs)               { return Impl::operator=(rhs); }

private:
    T the_value;
};

 
              
#ifdef XLC_QNOTEMPINC
#include "AutoDeriv/TaylorCoefficient1d.c"
#endif
              
#include "Array/ArrayTuplize.h"

template<class T>
ostream& operator<<(ostream& os, const TaylorCoefficient1d<T>& m){ 
    os << "[" <<  m.value() << " ";
    arrayTuplize(m,os);
    return os << "]" << endl;
}

#endif

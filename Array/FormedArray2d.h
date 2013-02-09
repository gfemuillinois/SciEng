/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedArray2dH
#define FormedArray2dH

#include "Array/ConcreteFormedArray2d.h"
#include "Array/InterfacedArray2d.h"


template<class T>
class FormedArray2d :              
    public InterfacedArray2d< ConcreteFormedArray2d<T> > {
public:
    FormedArray2d(Subscript n0, Subscript n1) : InterfacedArray2d< ConcreteFormedArray2d<T> >(n0, n1) {}
    FormedArray2d(const ConstArray2d<T>& a) :   InterfacedArray2d< ConcreteFormedArray2d<T> >(a) {}

    virtual void reshape(const SubscriptArray<2>& s)     { the_concrete.reshape(s); }

    virtual Array2d<T>& operator=(const ConstArray2d<T>& rhs) {
        return InterfacedArray2d< ConcreteFormedArray2d<T> >::operator=(rhs);
    }
    virtual Array2d<T>& operator=(const T& rhs) {
        return InterfacedArray2d< ConcreteFormedArray2d<T> >::operator=(rhs);
    }


    virtual const T* firstDatum() const { return the_concrete.firstDatum(); }
    virtual       T* firstDatum()       { return the_concrete.firstDatum(); }

protected:
  using InterfacedArray2d< ConcreteFormedArray2d<T> >::the_concrete;

};


#endif

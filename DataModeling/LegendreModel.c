/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Function/LegendrePolynomial.h"


template<class T>
LegendreModel<T>::
LegendreModel(Subscript max_power) : 
    polynomials(max_power + 1) {
    for (int i = 0; i < polynomials.numElts(); i++) { 
        polynomials(i) = LegendrePolynomial<T>(i);
    }
}



template<class T>
TaylorCoefficient1d<T>  LegendreModel<T>::operator()(const T& x) const { 
    TaylorCoefficient1d<T> a(0.0,polynomials.numElts());

    for (int i = 0; i < polynomials.numElts(); i++ ) {  
        a(i) = polynomials(i)(x);
    }
    return a;
}


template<class T>
LegendreModel<T>*  LegendreModel<T>::clone() const {
  return new LegendreModel<T>(*this);
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"
template<class T>
void ElasticArithmetic1d<T>::reshape(const SubscriptArray<1>& ea){ 
    Subscript n_elts_to_copy = min(shape(0), ea(0));
    ConcreteFormedArray1d<T> tmp(*this);
    ConcreteFormedArray1d<T>::reshape(ea); // Change internal pointer to new shape.
    (*this) = 0;                           // Make it all zero first.
    for (Subscript i = 0; i < n_elts_to_copy; i++) {
    (*this)(i) = tmp(i);
    }
}

template<class T>
void ElasticArithmetic2d<T>::reshape(const SubscriptArray<2>& ea){ 
    Subscript n_rows_to_copy = min(shape(0),ea(0));
    Subscript n_cols_to_copy = min(shape(1),ea(0));
    ConcreteFormedArray2d<T> tmp(*this);   // This copy is not needed if we did pointer swapping.
    ConcreteFormedArray2d<T>::reshape(ea); // Change internal pointer to new shape.
    (*this) = 0;                           // Make it all zero first.
    for (Subscript i = 0; i < n_rows_to_copy; i++) {
    for (Subscipt j = 0; j < n_cols_to_copy; j++) {
    (*this)(i,j) = tmp(i,j);
    }
    }
}


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
void DampedRectSVDRep<T>::Factored::pseudoInvert(ConcreteBlas1d<T>& b) {
    for (Subscript i = 0; i < k; i++) {
        T s_i = sigma(i);
        b(i) *= s_i / ( sqr(s_i) + lambda2 );
    }
}


template<class T>
void DampedRectSVDRep<T>::Factored::pseudoInvert(ConcreteBlas2d<T>& b) {
    for (Subscript i = 0; i < k; i++) {
    T s_i = sigma(i);
    b.row(i) *= s_i / ( sqr(s_i) + lambda2 );
    }
}


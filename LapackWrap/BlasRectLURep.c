/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"
#include "LapackWrap/LapackSubroutines.h"

template<class T>
BlasRectLURep<T>::Factored::Factored(BlasRectLURep<T>::Unfactored* mp) :

    pivots( min(mp->shape(0), mp->shape(1)) ), 
    facmat_p(mp)                               {

    int info;  // info return from LAPACK factor routine.
    LapackSubroutines::xgetrf(mp->shape(0), mp->shape(1), &(*mp)(0,0), mp->shape(0), &pivots(0), info);
    if (info != 0) throw LapackErr::UnableToFactor(info);
}

template<class T>
void BlasRectLURep<T>::Factored::solve(ConcreteBlas2d<T>& b) {
    int info;  // info return from LAPACK solve routine.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), b.shape(1), &(*facmat_p)(0,0),
    	                         facmat_p->shape(0), &pivots(0), b.firstDatum(), b.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void BlasRectLURep<T>::Factored::solve(ConcreteBlas1d<T>& b) {
    int info;  // info return from LAPACK solve routine.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), 1, &(*facmat_p)(0,0),
    	                         facmat_p->shape(0), &pivots(0), b.firstDatum(), b.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void BlasRectLURep<T>::Factored::solve(ConcreteBlas2d<T>& x, const ConcreteBlas2d<T>& b) {
    int info;  // info return from LAPACK solve routine.
    x = b;  // For LU, x and b are same size and Lapack overwrites b with x.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), x.shape(1), &(*facmat_p)(0,0),
    	                         facmat_p->shape(0), &pivots(0), x.firstDatum(), x.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void BlasRectLURep<T>::Factored::solve(ConcreteBlas1d<T>& x, const ConcreteBlas1d<T>& b) {
    int info;  // info return from LAPACK solve routine.
    x = b;  // For LU, x and b are same size and Lapack overwrites b with x.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), x.shape(1), &(*facmat_p)(0,0),
    	                         facmat_p->shape(0), &pivots(0), x.firstDatum(), x.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}


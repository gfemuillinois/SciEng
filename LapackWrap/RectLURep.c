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
RectLURep<T>::Factored::Factored(RectLURep<T>::Unfactored* mp) :

    pivots( min(mp->shape(0), mp->shape(1)) ), 
    facmat_p(mp)                               {


    int info;  // info return from LAPACK factor routine.

    LapackSubroutines::xgetrf(mp->shape(0), mp->shape(1), mp->firstDatum(), mp->shape(0), 
                              pivots.firstDatum(), info);

    if (info != 0) throw LapackErr::UnableToFactor(info);
}


template<class T>
void RectLURep<T>::Factored::solve(ConcreteFortranArray2d<T>& b) {
    int info;  // info return from LAPACK solve routine.

    LapackSubroutines::xgetrs(
          "No transpose", facmat_p->shape(0), b.shape(1), facmat_p->firstDatum(),
    	     facmat_p->shape(0), pivots.firstDatum(), b.firstDatum(), b.shape(0), info
                             );

    if (info != 0) throw LapackErr::UnableToSolve(info);
}


template<class T>
void RectLURep<T>::Factored::solve(ConcreteFortranArray1d<T>& b) {
    int info;  // info return from LAPACK solve routine.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), 1, facmat_p->firstDatum(),
    	                         facmat_p->shape(0), pivots.firstDatum(), b.firstDatum(), b.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void RectLURep<T>::Factored::solve(ConcreteFortranArray2d<T>& x, const ConcreteFortranArray2d<T>& b) {
    int info;  // info return from LAPACK solve routine.
    x = b;  // For LU, x and b are same size and Lapack overwrites b with x.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), x.shape(1), facmat_p->firstDatum(),
    	                         facmat_p->shape(0), pivots.firstDatum(), x.firstDatum(), x.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void RectLURep<T>::Factored::solve(ConcreteFortranArray1d<T>& x, const ConcreteFortranArray1d<T>& b) {
    int info;  // info return from LAPACK solve routine.
    x = b;  // For LU, x and b are same size and Lapack overwrites b with x.

    LapackSubroutines::xgetrs("No transpose", facmat_p->shape(0), x.shape(1), facmat_p->firstDatum(),
    	                         facmat_p->shape(0), pivots.firstDatum(), x.firstDatum(), x.shape(0), info);

    if (info != 0) throw LapackErr::UnableToSolve(info);
}


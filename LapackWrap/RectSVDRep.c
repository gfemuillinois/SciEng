/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"
#include "SciEng/NumericalLimits.h"
#include "LapackWrap/LapackSubroutines.h"


template<class T>
RectSVDRep<T>::Factored::Factored(RectSVDRep<T>::Unfactored* mp) :

    facmat_p(mp),
    m( mp->shape(0) ),
    n( mp->shape(1) ), 
    k( min(m, n) ),
    sigma(k),          // k X k diagonal matrix, stored as vector
    u(m, k),           // m X k
    v_T(k, n) {        // k X n


    // Minimum size work area required by LAPACK
    ConcreteFortranArray1d<T> work( max(3 * k + max(m,n), 5 * k - 4) );

    int info;  // info return from LAPACK factor routine.
    LapackSubroutines::xgesvd( 

        LapackSubroutines::separate,   // Give just left singular vectors, in u.
        LapackSubroutines::separate,   // Give just right singular vectors, in v_t.


        m, n, mp->firstDatum(), mp->shape(0),   // A
        sigma.firstDatum(),                     // sigma's
        u.firstDatum(), u.shape(0),             // U
        v_T.firstDatum(), v_T.shape(0),         // V^T
        work.firstDatum(), work.numElts(),      // Work area
        info                                    // Return code

    ); 
    if (info != 0) throw LapackErr::UnableToFactorSVD(info);
}


#include "LapackWrap/TransposedConcreteBlas2d.h"

template<class T>
void RectSVDRep<T>::Factored::solve(RectSVDRep<T>::Knowns2d& b) {

    b = TransposedConcreteBlas2d<T>(u) * b;     // U^T * b
    pseudoInvert(b);                            // sigma~^+ * b
    b = TransposedConcreteBlas2d<T>(v_T) * b;   // V * b

}



template<class T>
void RectSVDRep<T>::Factored::pseudoInvert(RectSVDRep<T>::Knowns2d& b) {
    T tol = zeroingTol();
    for (Subscript i = 0; i < k; i++) {
        if ( sigma(i) < tol ) b.row(i) = T(0);
        else b.row(i) *= T(1) / sigma(i);
    }
}



template<class T>
T RectSVDRep<T>::Factored::zeroingTol() const {
    return NumericalLimits<T>::epsilon * n * sigma(0);
}


template<class T>
void RectSVDRep<T>::Factored::solve(RectSVDRep<T>::Unknowns2d& x, const RectSVDRep<T>::Knowns2d& b) {
    TransposedConcreteBlas2d<T> u_T(u);
    x = u_T * b;                     
    pseudoInvert(x);                 
    x = TransposedConcreteBlas2d<T>(v_T) * x;
}

template<class T>
void RectSVDRep<T>::Factored::solve(RectSVDRep<T>::Knowns1d& b) {

    b = TransposedConcreteBlas2d<T>(u) * b;
    pseudoInvert(b);                 
    b = TransposedConcreteBlas2d<T>(v_T) * b;

}


template<class T>
void RectSVDRep<T>::Factored::solve(RectSVDRep<T>::Unknowns1d& x, const RectSVDRep<T>::Knowns1d& b) {
    TransposedConcreteBlas2d<T> u_T(u);
    x = u_T * b;                     
    pseudoInvert(x);                 
    x = TransposedConcreteBlas2d<T>(v_T) * x;
}

template<class T>
void RectSVDRep<T>::Factored::pseudoInvert(RectSVDRep<T>::Knowns1d& b) {
    T tol = zeroingTol();
    for (Subscript i = 0; i < k; i++) {
    if ( sigma(i) < tol ) b(i) = T(0);
    else b(i) *= T(1) / sigma(i);
    }
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RectSVDRepH
#define RectSVDRepH

#include "LapackWrap/Lapack.h"
#include "LapackWrap/ConcreteBlas2d.h"


template<class T>
class RectSVDRep {
public:

    typedef ConcreteBlas2d<T> Unfactored;    // The type of A in Ax = b;
    typedef ConcreteBlas2d<T> Unknowns2d;    // The type of x in Ax = b;
    typedef ConcreteBlas2d<T> Knowns2d;      // The type of b in Ax = b;
    typedef ConcreteBlas1d<T> Unknowns1d;    // The type of x in Ax = b;
    typedef ConcreteBlas1d<T> Knowns1d;      // The type of b in Ax = b;


    class Factored {
    public:
        Factored(RectSVDRep<T>::Unfactored* mp);
	virtual ~Factored() {}

        void solve(Knowns1d& b); // Overwrites b with x
        void solve(Unknowns1d& x, const Knowns1d& b);
        void solve(Knowns2d& b); // Overwrites b with x
        void solve(Unknowns2d& x, const Knowns2d& b);


        Knowns1d&   singularValues()        { return sigma; }
        Unknowns2d& rightSingularVectorsT() { return v_T;   }
        Knowns2d&   leftSingularVectors()   { return u;     }


    protected:

        virtual void pseudoInvert(Knowns2d& uTb);    // U^T * b * sigma^+
        virtual void pseudoInvert(Knowns1d& uTb);

        virtual T zeroingTol() const;                // Tolerance for zeroing sigma_i



        CopiedObjPtr<RectSVDRep<T>::Unfactored> facmat_p;  // Factored matrix pointer
        Subscript                               m;         // Number of rows in A
        Subscript                               n;         // Number of columns in A
        Subscript                               k;         // min(m,n), size of matrices.
        Knowns1d                                sigma;     // Singular values
        Unknowns2d                              v_T;       // Right singular vectors, transposed
        Knowns2d                                u;         // Left singular vectors

    };
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/RectSVDRep.c"
#endif

#endif

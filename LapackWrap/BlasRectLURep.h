/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef BlasRectLURepH
#define BlasRectLURepH

#include "LapackWrap/ConcreteBlas2d.h"
#include "LapackWrap/ConcreteBlas1d.h"
#include "Array/ConcreteFortranArray1d.h"


template<class T>
class BlasRectLURep {
public:
    typedef ConcreteBlas2d<T> Unfactored;
    typedef ConcreteBlas2d<T> Unknowns2d;
    typedef ConcreteBlas2d<T> Knowns2d;
    typedef ConcreteBlas1d<T> Unknowns1d;
    typedef ConcreteBlas1d<T> Knowns1d;

    class Factored {
    public:
        Factored(BlasRectLURep<T>::Unfactored* mp);
        void solve(ConcreteBlas2d<T>&);
        void solve(ConcreteBlas2d<T>& x, const ConcreteBlas2d<T>& b);
        void solve(ConcreteBlas1d<T>&);
        void solve(ConcreteBlas1d<T>& x, const ConcreteBlas1d<T>& b);
    private:

        CopiedObjPtr< BlasRectLURep<T>::Unfactored > facmat_p;      // Factored matrix pointer
        ConcreteFortranArray1d<int>                  pivots;        // Pivots

    };
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/BlasRectLURep.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RectLURepH
#define RectLURepH

#include "Array/ConcreteFortranArray1d.h"
#include "Array/ConcreteFortranArray2d.h"


template<class T>
class RectLURep {
public:
    typedef ConcreteFortranArray2d<T> Unfactored;
    typedef ConcreteFortranArray1d<T> Unknowns1d;
    typedef ConcreteFortranArray1d<T> Knowns1d;
    typedef ConcreteFortranArray2d<T> Unknowns2d;
    typedef ConcreteFortranArray2d<T> Knowns2d;

    class Factored {
    public:
        Factored(RectLURep<T>::Unfactored* mp);
        void solve(ConcreteFortranArray2d<T>&);
        void solve(ConcreteFortranArray2d<T>& x, const ConcreteFortranArray2d<T>& b);
        void solve(ConcreteFortranArray1d<T>&);
        void solve(ConcreteFortranArray1d<T>& x, const ConcreteFortranArray1d<T>& b);
    private:

        CopiedObjPtr< RectLURep<T>::Unfactored > facmat_p;      // Factored matrix pointer
        ConcreteFortranArray1d<int>              pivots;        // Pivots

    };
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/RectLURep.c"
#endif

#endif

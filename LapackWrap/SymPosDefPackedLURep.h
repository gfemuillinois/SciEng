/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SymPosDefPackedLURepH
#define SymPosDefPackedLURepH

#include "Array/ConcreteFortranSymmetricPackedArray2d.h"
#include "Array/ConcreteFortranArray1d.h"
#include "Array/ConcreteFortranArray2d.h"
#include "LapackWrap/Lapack.h"


template<class T>
class SymPosDefPackedLURep {
public:
    // These types are used for Ax=b in this implementation:

    typedef ConcreteFortranSymmetricPackedArray2d<T> Unfactored;   // A
    typedef ConcreteFortranArray1d<T> Unknowns1d;                  // x
    typedef ConcreteFortranArray1d<T> Knowns1d;                    // b
    typedef ConcreteFortranArray2d<T> Unknowns2d;                  // x
    typedef ConcreteFortranArray2d<T> Knowns2d;                    // b


    class Factored {
    public:
        Factored(SymPosDefPackedLURep<T>::Unfactored* mp);
        void solve(ConcreteFortranArray1d<T>&);
        void solve(ConcreteFortranArray1d<T>& x, const ConcreteFortranArray1d<T>& b);
        void solve(ConcreteFortranArray2d<T>&);
        void solve(ConcreteFortranArray2d<T>& x, const ConcreteFortranArray2d<T>& b);
    private:
        CopiedObjPtr< SymPosDefPackedLURep<T>::Unfactored > facmat_p; // Factored matrix pointer
    };
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/SymPosDefPackedLURep.c"
#endif

#endif

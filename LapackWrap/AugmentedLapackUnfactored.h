/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AugmentedLapackUnfactoredH
#define AugmentedLapackUnfactoredH

#include "LapackWrap/Lapack.h"


template<class Rep>
class AugmentedLapackUnfactored :        // A:b for problem Ax = b;  
    public virtual Array2d<Rep::Unfactored::EltT>,
    private LapackUnfactored<Rep> {
public:
    AugmentedLapackUnfactored(const ConstArray2d<EltT>& a, const ConstArray2d<EltT>& b);

    typedef Rep::Unfactored::EltT EltT;
    typedef Rep::Unknowns         Unknowns;
    typedef Rep::Knowns           Knowns;



    Array<EltT>& solve(Rep::Unknowns& x);      // factor and solve for x in-place.
    Array<EltT>& solve(Array1d<EltT>& x);      // factor and solve for x in-place.


    LapackUnfactored<Rep>::factor;
    LapackUnfactored<Rep>::rep;

    LapackUnfactored<Rep>::rank;
    LapackUnfactored<Rep>::shape;
    LapackUnfactored<Rep>::numElts;
    LapackUnfactored<Rep>::operator[];
    LapackUnfactored<Rep>::operator();

    AugmentedLapackUnfactored<Rep>& operator=(const AugmentedLapackUnfactored<Rep>& rhs){
    LapackUnfactored<Rep>::operator=(rhs);  // copy matrix.
    bp = rhs.bp;                          // Copy b from Ax=b.
    return *this;
    }

protected:
    AugmentedLapackUnfactored(Subscript nrows, Subscript ncols);
    Knowns& rhs() { return *bp; }
private:
    CopiedObjPtr<Rep::Knowns> bp;
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/AugmentedLapackUnfactored.c"
#endif

#endif

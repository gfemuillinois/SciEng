/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NormalizedLapackUnfactoredH
#define NormalizedLapackUnfactoredH

#include "LapackWrap/Lapack.h"
#include "LapackWrap/ColumnNorms.h"


template<class Rep>
class NormalizedLapackUnfactored : // Normalizes columns before factoring.           
    public LapackUnfactored<Rep> {
public:
    NormalizedLapackUnfactored(Subscript nrows, Subscript ncols) :
    LapackUnfactored<Rep>(nrows, ncols) {
    }

    NormalizedLapackFactored<Rep> factor();
    virtual Array2d<EltT>& operator=(const ConstArray2d<EltT>& rhs)           { return LapackUnfactored<Rep>::operator=(rhs); }
    virtual Array2d<EltT>& operator=(const EltT& rhs)                         { return LapackUnfactored<Rep>::operator=(rhs); }
    virtual Array2d<EltT>& operator=(const LapackUnfactored<Rep>& rhs)        { return LapackUnfactored<Rep>::operator=(rhs); }
    virtual Array2d<EltT>& operator=(const ConcreteFortranArray2d<EltT>& rhs) { return LapackUnfactored<Rep>::operator=(rhs); }

};


template<class Rep>
class NormalizedLapackFactored : // Normalizes solution after solving. 
    public LapackFactored<Rep> {
public:
    Rep::Unknowns1d& solve(Rep::Unknowns1d& b);  // Overwrites b with x.
    Rep::Unknowns1d& solve(Rep::Unknowns1d& x,const Rep::Knowns1d& b);

    Rep::Unknowns2d& solve(Rep::Unknowns2d& b);  // Overwrites b with x.
    Rep::Unknowns2d& solve(Rep::Unknowns2d& x,const Rep::Knowns2d& b);

protected:
    friend NormalizedLapackFactored<Rep> NormalizedLapackUnfactored<Rep>::factor();
    NormalizedLapackFactored(Rep::Factored* p, const CopiedObjPtr< ColumnNorms<Rep::Unfactored> >& n) :
    LapackFactored<Rep>(p),
    column_scalars(n) {
    }

private:
    CopiedObjPtr< ColumnNorms<Rep::Unfactored> >  column_scalars;
};

#ifdef XLC_QNOTEMPINC
#include "LapackWrap/NormalizedLapackUnfactored.c"
#endif

#endif

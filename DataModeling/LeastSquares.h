/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LeastSquaresH
#define LeastSquaresH

#include "DataModeling/PhysicalData.h"
#include "Function/Functional.h"
#include "AutoDeriv/TaylorCoefficient1d.h"
#include "LapackWrap/Lapack.h"


template<class A>
class LeastSquares :            
    public A {  // Will be e.g LapackUnfactored< RectSVDRep<double> >
public:
    typedef typename A::EltT EltT;
    typedef typename A::Representation::Unfactored Unfactored;
    typedef typename A::Representation::Unknowns2d Unknowns2d;
    typedef typename A::Representation::Knowns2d Knowns2d;
    typedef typename A::Representation::Unknowns1d Unknowns1d;
    typedef typename A::Representation::Knowns1d Knowns1d;

    LeastSquares( 
        const PhysicalData<EltT>& data,
        const Functional<EltT, TaylorCoefficient1d<EltT> >& model,
        Subscript nparms
    );
    LeastSquares<A>& operator=(const LeastSquares<A>& rhs); 


    EltT            chi2() const { return the_chi2; }
    const Knowns1d& rhs()  const { return b;        }


    // Assignment operators ... not shown ...
    virtual Array2d<EltT>& operator=(const ConstArray2d<EltT>& rhs)                  { return A::operator=(rhs); }
    virtual Array2d<EltT>& operator=(const EltT& rhs)                                { return A::operator=(rhs); }
    virtual Array2d<EltT>& operator=(const LapackUnfactored<A::Representation>& rhs) { return A::operator=(rhs); }
    virtual Array2d<EltT>& operator=(const ConcreteFortranArray2d<EltT>& rhs)        { return A::operator=(rhs); }
private:

    ConcreteBlas1d<EltT> b;
    EltT                 the_chi2;

};


#ifdef XLC_QNOTEMPINC
#include "DataModeling/LeastSquares.c"
#endif

#endif

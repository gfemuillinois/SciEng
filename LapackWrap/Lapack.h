/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LapackH
#define LapackH

#include "SciEng/CopiedObjPtr.h"
#include "SciEng/Boolean.h"
#include "Array/Array2d.h"
#include "Array/ConcreteFortranArray2d.h"

#include "LapackWrap/LapackErr.h"


template<class Rep> class LapackFactored; // Declare corresponding factored category

template<class Rep>
class LapackUnfactored :
    public virtual Array2d<typename Rep::Unfactored::EltT>        {
public:

    typedef Rep Representation;            // Factoring representation
    typedef typename Rep::Unfactored Unfactored;    // Factoring representation's unfactored form
    typedef typename Rep::Unfactored::EltT EltT;    // Element type


    LapackUnfactored(Subscript nrows, Subscript ncols);
    LapackUnfactored(const LapackUnfactored<Rep>&);
    LapackUnfactored(const ConstArray2d<EltT>&);
    LapackUnfactored(const ConcreteFortranArray2d<EltT>&);
    LapackFactored<Rep> factor();
    // ...

    // Array interface declarations ...
    virtual Dimension dim() const;
    virtual Subscript shape(Dimension d) const;
    virtual const EltT& operator()(Subscript, Subscript) const;
    virtual       EltT& operator()(Subscript, Subscript);
    virtual typename Array2d<EltT>::ConstProjectionT project(Subscript, Dimension) const;
    virtual      typename Array2d<EltT>::ProjectionT project(Subscript, Dimension);
    virtual Array2d<EltT>& operator=(const LapackUnfactored<Rep>& rhs);
    virtual Array2d<EltT>& operator=(const ConstArray2d<EltT>& rhs);
    virtual Array2d<EltT>& operator=(const ConcreteFortranArray2d<EltT>& rhs);
    virtual Array2d<EltT>& operator=(const EltT& rhs);
    virtual typename Rep::Unfactored&       rep()       { checkValidity(); return *ap; } // checked accessor 
    virtual const typename Rep::Unfactored& rep() const { checkValidity(); return *ap; } // checked accessor 
protected:
    typename Rep::Unfactored* releaseControl(); 
    void checkValidity() const; // Throw exception if not valid
private:

    CopiedObjPtr<typename Rep::Unfactored> ap;
    Boolean                       valid;



};



template<class Rep>
class LapackFactored {
public:

    typedef typename Rep::Unfactored::EltT EltT; // Element type

    typedef typename Rep::Unknowns1d Unknowns1d; // Single right-hand-side
    typedef typename Rep::Knowns1d Knowns1d;

    typedef typename Rep::Unknowns2d Unknowns2d; // Multiple right-hand-sides
    typedef typename Rep::Knowns2d Knowns2d;


    typename Rep::Unknowns1d& solve(typename Rep::Unknowns1d& b);  // Overwrites b with x.
    typename Rep::Unknowns1d& solve(typename Rep::Unknowns1d& x, const typename Rep::Knowns1d& b);

    typename Rep::Unknowns2d& solve(typename Rep::Unknowns2d& b);  // Overwrites b with x.
    typename Rep::Unknowns2d& solve(typename Rep::Unknowns2d& x, const typename Rep::Knowns2d& b);

    typename Rep::Factored& rep()       { return *ap; }
    const typename Rep::Factored& rep() const { return *ap; }
protected:
    friend LapackFactored<Rep> LapackUnfactored<Rep>::factor();
    LapackFactored(typename Rep::Factored* p) : ap(p) {}
private:
    CopiedObjPtr<typename Rep::Factored> ap;
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/Lapack.c"
#endif

#endif

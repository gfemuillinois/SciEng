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
    public virtual Array2d<Rep::Unfactored::EltT>        {
public:

    typedef Rep Representation;            // Factoring representation
    typedef Rep::Unfactored Unfactored;    // Factoring representation's unfactored form
    typedef Rep::Unfactored::EltT EltT;    // Element type


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
    virtual ConstProjectionT project(Subscript, Dimension) const;
    virtual      ProjectionT project(Subscript, Dimension);
    virtual Array2d<EltT>& operator=(const LapackUnfactored<Rep>& rhs);
    virtual Array2d<EltT>& operator=(const ConstArray2d<EltT>& rhs);
    virtual Array2d<EltT>& operator=(const ConcreteFortranArray2d<EltT>& rhs);
    virtual Array2d<EltT>& operator=(const EltT& rhs);
    virtual Rep::Unfactored&       rep()       { checkValidity(); return *ap; } // checked accessor 
    virtual const Rep::Unfactored& rep() const { checkValidity(); return *ap; } // checked accessor 
protected:
    Rep::Unfactored* releaseControl(); 
    void checkValidity() const; // Throw exception if not valid
private:

    CopiedObjPtr<Rep::Unfactored> ap;
    Boolean                       valid;



};



template<class Rep>
class LapackFactored {
public:

    typedef Rep::Unfactored::EltT EltT; // Element type

    typedef Rep::Unknowns1d Unknowns1d; // Single right-hand-side
    typedef Rep::Knowns1d Knowns1d;

    typedef Rep::Unknowns2d Unknowns2d; // Multiple right-hand-sides
    typedef Rep::Knowns2d Knowns2d;


    Rep::Unknowns1d& solve(Rep::Unknowns1d& b);  // Overwrites b with x.
    Rep::Unknowns1d& solve(Rep::Unknowns1d& x, const Rep::Knowns1d& b);

    Rep::Unknowns2d& solve(Rep::Unknowns2d& b);  // Overwrites b with x.
    Rep::Unknowns2d& solve(Rep::Unknowns2d& x, const Rep::Knowns2d& b);

    Rep::Factored& rep()       { return *ap; }
    const Rep::Factored& rep() const { return *ap; }
protected:
    friend LapackFactored<Rep> LapackUnfactored<Rep>::factor();
    LapackFactored(Rep::Factored* p) : ap(p) {}
private:
    CopiedObjPtr<Rep::Factored> ap;
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/Lapack.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FunctionAlgebraH
#define FunctionAlgebraH

#include <math.h>
#include "SciEng/Ptrs.h"
#include "Algebra/DivisionAlgebraCategory.h"
#include "Function/Functional.h"
#include "Function/ZeroFunctional.h"
#include "Function/OneFunctional.h"
#include "Function/XFunctional.h"
#include "Function/ConstantFunctional.h"
#include "Function/BinaryFunctional.h"
#include "Function/UnaryFunctional.h"
#include "Function/CompositionFunctional.h"
#include "Function/ParameterFunctional.h"



template<class Domain>
class FunctionalAlgebra :      
    public virtual IsoFunctional<Domain>,
    public DivisionAlgebraCategory< FunctionalAlgebra<Domain>, Domain > {
public:



    FunctionalAlgebra(const CountedBuiltInPtr<Domain>& d); // Means a parameter
    FunctionalAlgebra(const Domain& d);                    // Means a constant.
    FunctionalAlgebra();                                   // Means a variable (x).
    FunctionalAlgebra(const IsoFunctional<Domain>& fp);    // Means a function to be copied.
    FunctionalAlgebra(IsoFunctional<Domain>* just_newed);  // Means a function, don't copy.





    virtual Domain                           operator()(const Domain& v) const { return (*f)(v); }
    CloneableObjPtr< IsoFunctional<Domain> > operator()(const FunctionalAlgebra<Domain>& inner) const;


    // DivisionAlgebraCategory User Must Define.
    FunctionalAlgebra<Domain>& operator+=(const FunctionalAlgebra<Domain>& rhs);
    FunctionalAlgebra<Domain>& operator-=(const FunctionalAlgebra<Domain>& rhs);
    FunctionalAlgebra<Domain>& operator*=(const FunctionalAlgebra<Domain>& rhs);
    FunctionalAlgebra<Domain>& operator/=(const FunctionalAlgebra<Domain>& rhs);
    FunctionalAlgebra<Domain>& operator*=(const Domain&);
    FunctionalAlgebra<Domain>& operator/=(const Domain&);
    FunctionalAlgebra<Domain>& setToZero();
    FunctionalAlgebra<Domain>& setToOne();
    FunctionalAlgebra<Domain>& negate();
    FunctionalAlgebra<Domain>& invert();

    // Transcendental functions
    friend FunctionalAlgebra<Domain> exp(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> log(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> sqrt(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> log10(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> sin(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> cos(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> asin(const FunctionalAlgebra<Domain>&);
    friend FunctionalAlgebra<Domain> acos(const FunctionalAlgebra<Domain>&);

    virtual FunctionalAlgebra<Domain>* clone() const { return new FunctionalAlgebra<Domain>(*this); }
private:
    CloneableObjPtr< IsoFunctional<Domain> > f;
};


#ifdef XLC_QNOTEMPINC
#include "Function/FunctionalAlgebra.c"
#endif

#endif

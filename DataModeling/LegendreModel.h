/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LegendreModelH
#define LegendreModelH

#include "AutoDeriv/TaylorCoefficient1d.h"
#include "SciEng/Ptrs.h"
#include "SciEng/Subscript.h"
#include "Function/Functional.h"
#include "Array/ConcreteFormedArray1d.h"
#include "Function/LegendrePolynomial.h"
                                 

template<class T>
class LegendreModel : 
    public virtual Functional<T, TaylorCoefficient1d<T>  > {
public:
    LegendreModel(Subscript max_power);
    virtual TaylorCoefficient1d<T> operator()(const T& x) const;
    virtual LegendreModel<T>* clone() const;
private:
    ConcreteFormedArray1d< LegendrePolynomial<T> > polynomials;
};


#ifdef XLC_QNOTEMPINC
#include "DataModeling/LegendreModel.c"
#endif
      
#endif

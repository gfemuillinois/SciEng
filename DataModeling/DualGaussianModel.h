/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DualGaussianModelH
#define DualGaussianModelH
#include "DataModeling/DataModel.h"
#include "Array/RigidArray.h"
#include "AutoDeriv/RigidRall1d.h"


template<class T>
class DualGaussianModel : 
    public virtual DataModel<T> {
public:
    DualGaussianModel(T a0, T a1, T a2, T a3, T a4, T a5);

    virtual const Array1d<T>& parameters() const;
    virtual       Array1d<T>& parameters();


    virtual TaylorCoefficient1d<T> operator()(const T& x) const;

    virtual DualGaussianModel<T>*  clone()                const;
private:
    RigidArray1d<T, 6> a_values;
};


#ifdef XLC_QNOTEMPINC
#include "DataModeling/DualGaussianModel.c"
#endif

#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef NewtonRaphsonIteratedEquationsH
#define NewtonRaphsonIteratedEquationsH

#include "DataModeling/IteratedEquations.h"
#include "Function/Function.h"
#include "SciEng/NumericalLimits.h"
#include "Array/FormedArray.h"
#include "LapackWrap/ConcreteBlas1d.h"

/* NewtonRaphsonIteratedEquations represent simultaneous equations as an array of functions */


template<class RallT>
class NewtonRaphsonFunction { 
public:
    typedef RallT (*RallFunctionType)(const Array1d<RallT>& a); // Type for f_i(a)

    // Construct from built-in function
    NewtonRaphsonFunction(RallFunctionType fp = 0) : f_i(fp) {}

    // Evaluate f_i(a)
    TaylorCoefficient1d<RallT::EltT> operator()(const Array1d<RallT>& a) const { 
        return reform(f_i(a)); 
    }
private:
    RallFunctionType f_i;
};

 

template<class RallT>
class NewtonRaphsonIteratedEquations :            
    public virtual IteratedEquations<RallT::EltT>,
    public virtual Array1d< NewtonRaphsonFunction<RallT> >,  
    private FormedArray1d< NewtonRaphsonFunction<RallT> >  {
public:
    typedef RallT::EltT T;
    NewtonRaphsonIteratedEquations(                   
        int n_eqns,
        T function_convergence = NumericalLimits<T>::epsilon
    );


    // RallT::EltT needed by xlC, why not T?  
    virtual RallT::EltT update(Array1d<RallT::EltT>& a);
    virtual Boolean     converged() const;


    // Assignment operators ... not shown
private:
    typedef FormedArray1d< NewtonRaphsonFunction<RallT> > Impl;
public:
    Impl::operator();
    virtual Array1d<EltT>& operator=(const ConstArray1d<EltT>& rhs) { return Impl::operator=(rhs); }
    virtual Array1d<EltT>& operator=(const EltT& rhs)               { return Impl::operator=(rhs); }
private:
    T   function_value;
    T   function_value_convergence;
};

  

#ifdef XLC_QNOTEMPINC
#include "DataModeling/NewtonRaphsonIteratedEquations.c"
#endif

#endif

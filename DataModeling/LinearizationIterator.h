/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LinearizationIteratorH
#define LinearizationIteratorH
                        
#include "Array/FormedArray.h"
#include "DataModeling/IteratedEquations.h"


template<class T>
class LinearizationIterator { 
public:
    LinearizationIterator( 
        IteratedEquations<T>& eqns,
        const Array1d<T>& initial_values,
        int maximum_iterations,
        T update_convergence =  default_correction_convergence
    );

    Boolean           more()    const;
    void              advance();
    const Array1d<T>& current() const { return cur; }


    void solve();

    static T default_correction_convergence;
    friend ostream& operator<<(ostream& os, const LinearizationIterator<T>& l);
protected:
    IteratedEquations<T>& the_eqns;
    FormedArray1d<T>  cur;

    int the_max_iters;
    int the_iters;

    T correction_norm;
    T correction_convergence; // Tested for no movement towards root.
};



#ifdef XLC_QNOTEMPINC
#include "DataModeling/LinearizationIterator.c"
#endif
    
#endif

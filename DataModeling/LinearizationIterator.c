/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/NumericalLimits.h"

template<class T>
T LinearizationIterator<T>::
default_correction_convergence(NumericalLimits<T>::epsilon);

template<class T>
LinearizationIterator<T>::
LinearizationIterator(IteratedEquations<T>& eqn, const Array1d<T>& init_values, int max_iters, T limit) :
    the_eqns(eqn),
    cur(init_values),
    the_max_iters(max_iters),
    correction_convergence(limit),
    the_iters(0),
    correction_norm(0.) {
}


template<class T>
Boolean LinearizationIterator<T>::more() const { 
    if (the_iters == 0) return Boolean::IsTrue;  // no info yet.
    return  
        the_iters < the_max_iters && 
        !the_eqns.converged() &&
        correction_norm >= correction_convergence; 
}



template<class T>
void LinearizationIterator<T>::advance(){ 
    correction_norm = the_eqns.update(cur);
    the_iters++;
}



template<class T>
void LinearizationIterator<T>::solve() { 
    while (more()) {
        advance();
        cout << *this << endl;
    }
}



// Needs iostream and iomanip...
#include <iostream>
#include <iomanip>

template<class T>
ostream& operator<<(ostream& os, const LinearizationIterator<T>& l) { 

    os << "Iteration: " << l.the_iters <<
          " correction norm: " << setw(10) << setprecision(3) << l.correction_norm <<
          " Parameters:" << l.current();

    return os;
}



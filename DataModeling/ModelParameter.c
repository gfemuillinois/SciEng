/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class RallT>
ModelParameter<RallT>::ModelParameter(double initial_guess) :  
    CountedBuiltInPtr<RallT>( new RallT(initial_guess) ),
    FunctionalAlgebra<RallT>( (const CountedBuiltInPtr<RallT>&)(*this) ) {
}


template<class RallT>
ModelParameter<RallT>::
ModelParameter(double initial_guess, Subscript i_th, Subscript nparms) :   
    CountedBuiltInPtr<RallT>( new RallT(initial_guess, i_th, nparms) ),
    FunctionalAlgebra<RallT>( (const CountedBuiltInPtr<RallT>&)(*this) ) {
}



template<class RallT>
ModelParameter<RallT>& ModelParameter<RallT>::
operator=(double rhs){  
    CountedBuiltInPtr<RallT>::operator*().value() = rhs;
    return *this;
}


template<class RallT>
ModelParameter<RallT>& 
ModelParameter<RallT>::operator=(const ModelParameter<RallT>& rhs){
  CountedBuiltInPtr<RallT>::operator=(rhs);
  FunctionalAlgebra<RallT>::operator=(rhs);
  return *this;
}

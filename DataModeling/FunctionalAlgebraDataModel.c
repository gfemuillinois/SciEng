/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
FunctionalAlgebraDataModel<T>::FunctionalAlgebraDataModel(
        const FunctionalAlgebra<RallT>& m,
        const DataModelParameters<RallT,T>& v
        ):
    parms(v),
    f(m) {
}
  
template<class T>
FunctionalAlgebraDataModel<T>::
    FunctionalAlgebraDataModel(Subscript number_of_variables) :
    parms(number_of_variables) {
}


template<class T>
TaylorCoefficient1d<T>
FunctionalAlgebraDataModel<T>::operator()(const T& coordinate) const {  
    // Convert to RallT, evaluate model function, re-convert
    return reform(f( RallT(coordinate, parms.numElts()) )); 
}


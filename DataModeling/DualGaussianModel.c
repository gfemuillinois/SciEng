/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
DualGaussianModel<T>::
DualGaussianModel(T a0, T a1, T a2, T a3, T a4, T a5) {
    a_values(0) = a0;
    a_values(1) = a1;
    a_values(2) = a2;
    a_values(3) = a3;
    a_values(4) = a4;
    a_values(5) = a5;
}

template<class T>
const Array1d<T>& DualGaussianModel<T>::parameters() const {
    return a_values;
}

template<class T>
Array1d<T>& DualGaussianModel<T>::parameters() {
    return a_values;
}


template<class T>
TaylorCoefficient1d<T> DualGaussianModel<T>::operator()(const T& x_coord) const {
    typedef RigidRall1d<T, 6>  RallT;
    RallT x(x_coord);
    RigidArray1d<RallT, 6> a;
    for (Subscript i = 0; i < 6; i++) {
        a(i) = RallT(a_values(i), i, 6);
    }

    return reform(
        a(0) * exp( -sqr( (x - a(1)) / a(2) ) ) +
        a(3) * exp( -sqr( (x - a(4)) / a(5) ) )
    );
}


template<class T>
DualGaussianModel<T>* DualGaussianModel<T>::clone() const {
  return new DualGaussianModel<T>(*this);
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T, Subscript nvars>
RigidRall1d<T,nvars>::
RigidRall1d(): Rall1d<T,RigidArithmetic1d<T,nvars> >(0.,RigidArithmetic1d<T,nvars>()) {
}

template<class T, Subscript nvars>
RigidRall1d<T,nvars>::
RigidRall1d(const T& t):
    Rall1d<T,RigidArithmetic1d<T,nvars> >(t,RigidArithmetic1d<T,nvars>()) {
    the_gradient=0.;
}

template<class T, Subscript nvars>
RigidRall1d<T,nvars>::
RigidRall1d(int i_th, const T&t): Rall1d<T,RigidArithmetic1d<T,nvars> >(t,RigidArithmetic1d<T,nvars>()) {
    the_gradient=0.;
    the_gradient(i_th) = 1.;
}


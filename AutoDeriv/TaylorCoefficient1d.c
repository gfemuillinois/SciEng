/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
TaylorCoefficient1d<T>::TaylorCoefficient1d(const T& value, Subscript n_grads) :
  FormedArray1d<T>(n_grads), 
  the_value(value) {
}

template<class T>
TaylorCoefficient1d<T>::TaylorCoefficient1d(const T& value, const ConstArray1d<T>& gradients) :
    FormedArray1d<T>(gradients),
    the_value(value) {
}

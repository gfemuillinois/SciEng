// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include <iostream>

#include "Array/FormedArray.h"
#include "Array/RigidArray.h"

template istream & operator>><float>(istream &, Array1d<float> &);

template ostream & operator<<<float>(ostream &, ConstArray1d<float> const &);

template class RigidArray1d<float, 5>;

template class FormedArray1d<float>;

template class ConcreteFormedArray1d<float>;
#endif

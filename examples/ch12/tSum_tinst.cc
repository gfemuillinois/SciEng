// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/FormedArray.h"
#include "Array/RigidArray.h"
#include "examples/ch11/sum.h"

template double sum<double>(Array2d<double> const &);

template class FormedArray2d<double>;

template class RigidArray2d<double, 5, 5>;

template int sum<int>(Array2d<int> const &);

template class FormedArray2d<int>;

template class ConcreteFormedArray2d<double>;

template class ConcreteFormedArray2d<int>;
#endif

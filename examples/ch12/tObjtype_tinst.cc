// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE


#include "Array/RigidArray.h"

const int nrows = 3;
template class RigidArray2d<int, nrows, 2*nrows>;

//template class RigidArray2d<int, 3, 6>;

#endif

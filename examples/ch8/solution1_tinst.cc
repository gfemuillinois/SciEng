
// Dummy file to create the template instances used in solution1
//


#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch6/SimpleArray.h"

#include "examples/ch6/Point.h"

template class SimpleArray<int>;

template class SimpleArray<Point>;

template class SimpleArray< SimpleArray<int> >;

#endif

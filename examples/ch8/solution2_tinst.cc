
// Dummy file to create the template instances used in solution2
//


#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch6/SimpleArray.h"

#include "examples/ch6/Point.h"
#include "examples/ch8/Element.h"

template class SimpleArray<int>;

template class SimpleArray<Point>;

template class SimpleArray< Element >;

#endif

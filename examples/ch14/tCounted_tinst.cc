// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch6/Point.h"
#include "SciEng/CountedObjPtr.h"
#include "examples/ch6/SimpleArray.h"

#include "tCounted.h"

template class SimpleArray<CountedObjPtr<Point> >;

template class CountedBuiltInPtr<Point>;

template class CountedBuiltInPtr<Element>;

#endif

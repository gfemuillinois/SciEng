// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch11/CheckedSimpleArray.h"

#include "tCheckedSimpleArray.h"

template float average<float>(SimpleArray<float> &);

template class SimpleArray<float>;

template class SimpleArray<int>;

template class SimpleArray<CheckedSimpleArray<int> >;

template class SimpleArray<int *>;

#endif

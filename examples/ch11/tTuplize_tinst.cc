
// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch6/SimpleArray.h"
#include "examples/ch11/tuplize.h"

template class SimpleArray<int>;

template class SimpleArray<double>;

template ostream & tuplize<int>(ostream &, const SimpleArray<int> &);

template ostream & tuplize<double>(ostream &, const SimpleArray<double> &);

#endif

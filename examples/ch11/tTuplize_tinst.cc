
// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch6/SimpleArray.h"
#include "examples/ch11/tuplize.h"

template class SimpleArray<int>;

template class SimpleArray<double>;

template std::ostream & tuplize<int>(std::ostream &, const SimpleArray<int> &);

template std::ostream & tuplize<double>(std::ostream &, const SimpleArray<double> &);

#endif

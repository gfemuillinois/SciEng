// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/FormedArray2d.h"

#include "Array/Array2d.h"
#include "Array/Array1d.h"
#include "SciEng/utils.h"

#include "tDiagonal.h"

template class FormedArray2d<int>;

template class ConcreteFormedArray2d<int>;

template ostream & operator<< <int> 
(ostream &, ConstArray1d<int> const &);

template ostream & operator<< <int>
(ostream &, ConstArray2d<int> const &);

template void set_to_identity<int>(Array2d<int> &);



#endif

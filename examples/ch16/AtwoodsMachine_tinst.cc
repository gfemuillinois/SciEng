
// Dummy file to create the template instances

#ifdef NO_IMPLICIT_TEMPLATE

#include "AtwoodsMachine.h"
#include "DataModeling/FormedPhysicalData.h"
#include "Array/arrayCopy.h"
#include "SciEng/String.h"

template class SIConstants<double>;

template class BritishConstants<double>;

template std::ostream & operator<< <double, 0, 1, -2, 0, 0, 0, 0>
(std::ostream &, Physical<double, 0, 1, -2, 0, 0, 0, 0> const &);

template std::ostream & operator<< <double, 1, 1, -2, 0, 0, 0, 0>
(std::ostream &, Physical<double, 1, 1, -2, 0, 0, 0, 0> const &);

template class PhysicalData<double>;

template class  PhysicalDataBrowser<double>;

template class ConcreteFormedArray1d<double>;

template class AccessedPhysicalDataBrowser<double>;

template void arrayCopy<ConcreteRowMajorSubscriptor<1>, double>
(ConcreteArray1dRef<ConcreteRowMajorSubscriptor<1>, double> const &, ConstArray1d<double> const &);

//template String & operator<<<char [44]>(String &, char [44] const &);


#endif

// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "SciEng/CloneableObjPtr.h"
#include "Array/ConcreteFormedArray1d.h"

#include "tMolecule.h"

template class CloneableObjPtr<Atom>;

template class ConcreteFormedArray1d<CloneableObjPtr<Atom> >;

template class ConcreteArrayShape<1>;

#endif

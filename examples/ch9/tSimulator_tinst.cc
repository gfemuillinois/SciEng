// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch9/CheckedSimpleArray.h"

#include "SciEng/HandlerStack.h"
#include "SciEng/Terminate.h"
#include "SciEng/NewHandler.h"

class GPIBInstrumentSimulation;

template class CheckedSimpleArray< GPIBInstrumentSimulation * >;

template class HandlerStack< std::set_terminate >;

template class HandlerStack< std::set_new_handler >;


#endif

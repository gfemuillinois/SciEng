
#ifndef TMOLECULEH
#define TMOLECULEH

#include "SciEng/SciEngString.h"

class Atom { 
public:

    virtual String       name()         const = 0;
    virtual unsigned int atomicNumber() const = 0;
    virtual Atom*        clone()        const = 0;
    virtual              ~Atom() {}     

};

#endif

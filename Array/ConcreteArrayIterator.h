/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArrayIteratorH
#define ConcreteArrayIteratorH

#include "SciEng/Boolean.h"


template<class ConcreteArray>
class ConcreteArrayBrowser {              
public:
    ConcreteArrayBrowser(const ConcreteArray& anArray) : 
        cur(anArray.firstDatum()),
        end(cur + anArray.numElts()) {
    }


    Boolean                    more()    const { return cur < end; }
    void                       advance()       { cur++; }
    const ConcreteArray::EltT& current() const { return *cur; }


private:
    const ConcreteArray::EltT* cur;
    const ConcreteArray::EltT* end;

    friend class ConcreteArrayIterator<ConcreteArray>;
    ConcreteArrayBrowser(const ConcreteArray::EltT* c, const ConcreteArray::EltT* e) :
        cur(c), 
        end(e) {
    }
};



template<class ConcreteArray>
class ConcreteArrayIterator {  
public:
    ConcreteArrayIterator(ConcreteArray& anArray) : 
        cur(anArray.firstDatum()),
        end(cur + anArray.numElts()) {
    }

    Boolean more() const { return cur < end; }
    void    advance()    { cur++; }
    ConcreteArray::EltT& current() const { return *cur; }

    operator ConcreteArrayBrowser<ConcreteArray>() { 
        return ConcreteArrayBrowser<ConcreteArray>(cur, end); 
    }
private:
    ConcreteArray::EltT* cur;
    ConcreteArray::EltT* end;
};


#endif

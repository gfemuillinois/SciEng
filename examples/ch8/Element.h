

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include <iostream>

#include "examples/ch6/SimpleArray.h"

class Element {
public:

    int operator[](int i) const;
    int numNodes()        const;

    friend istream& operator>>(istream&, Element&);
private:
    SimpleArray<int> node_numbers;
};
#endif

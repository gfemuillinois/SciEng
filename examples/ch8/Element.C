
#include "examples/ch8/Element.h"


int Element::operator[](int i) const { return node_numbers[i];        }
int Element::numNodes()        const { return node_numbers.numElts(); }


istream& operator>>(istream& instream, Element& e) {
    int n;
    instream >> n;
    e.node_numbers.setSize(n);
    for (int i = 0; i < n; i++) instream >> e.node_numbers[i];
    return instream;
}



#ifndef _ELEMENT3_H_
#define _ELEMENT3_H_

#include <iostream>

#include "SciEng/Boolean.h"
#include "examples/ch6/SimpleArray.h"
#include "examples/ch6/Point.h"

class NodesOfElement;
class NodeReader;

typedef Point Node;

class Element {
public:
    friend NodesOfElement; // Iterator over nodes of an element

    friend void operator>>(NodeReader& reader, Element& e);
    friend ostream& operator<<(ostream& os, const Element& e);

    Number maxAngle() const;
private:
    SimpleArray<Node*> node_ptrs;
};


class NodesOfElement {
public:
    NodesOfElement(const Element& e) :
                           node_ptrs(e.node_ptrs), cur(e.node_ptrs.numElts()-1) {}

// Iteration

    Boolean more()    const { return cur >= 0;        }
    void    advance()       { --cur;                  }
    Node&   current() const { return *node_ptrs[cur]; }


// Neighbors of current iterate
    Node& ccwNeighbor() const { return *node_ptrs[(cur + 1) % node_ptrs.numElts()]; }
    Node& cwNeighbor() const {
                           int numNodes = node_ptrs.numElts();
                           return *node_ptrs[(cur + numNodes - 1) % numNodes];
    }
private:
    const SimpleArray<Node*>& node_ptrs;
    int cur;
};

#endif


#ifndef TCOUNTEDH
#define TCOUNTEDH

#include "examples/ch6/Point.h"
#include "SciEng/CountedObjPtr.h"

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
    SimpleArray< CountedObjPtr<Node> > node_ptrs;
};

inline Boolean operator==(const Element& lhs, const Element& rhs) { 
    return &lhs == &rhs;
}

inline Boolean operator!=(const Element& lhs, const Element& rhs) { 
    return !(lhs == rhs);
}

#endif

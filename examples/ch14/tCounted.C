/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <stdlib.h>
#include "SciEng/Boolean.h"
#include "examples/ch6/Point.h"
#include "examples/ch6/List.h"
#include "examples/ch6/SimpleArray.h"

#include "SciEng/CountedObjPtr.h"

// Redefine EXIT_SUCCESS and EXIT_FAILURE.  When this program works it should return
// EXIT_FAILURE, but run-test in the Makefile tests for EXIT_SUCCESS.
#undef EXIT_SUCCESS
#undef EXIT_FAILURE
#define EXIT_SUCCESS 1
#define EXIT_FAILURE 0

class ElementsOfMesh;
class NodesOfElement;
class NodesOfMesh;
class NodeReader;
class Mesh;


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


class Mesh {
public:

    friend ElementsOfMesh; // Iterator over elements of a mesh
    friend NodesOfMesh;    // Iterator over nodes of a mesh

    friend istream& operator>>(istream&, Mesh&);

    Boolean checkElementAngles(Number angle_threshold) const;
    void    remove(const List<CountedObjPtr<Element> >& trim);
private:
    List<CountedObjPtr<Element> > element_table;
};


class NodeReader {
public:
    NodeReader(int num_nodes, istream& instream);
    int   getSize();
    CountedObjPtr<Node> getNode();
private:
    SimpleArray< CountedObjPtr<Node> > node_table;
    istream& in;
};


class ElementsOfMesh :
    public ListIterator<CountedObjPtr<Element> > {
public:
    ElementsOfMesh(const Mesh& m) :
                           ListIterator<CountedObjPtr<Element> >(m.element_table) { }
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
    const SimpleArray< CountedObjPtr<Node> >& node_ptrs;
    int cur;
};



void trimTo(Mesh& m, const Point& bound) { 
    List<CountedObjPtr<Element> > trim;  // Accumulator for out of bound elements
    for (ElementsOfMesh elts(m); elts.more(); elts.advance()) { 
                           for (NodesOfElement nodes(*elts.current()); nodes.more(); nodes.advance()) { 
            if ( (nodes.current().x() > bound.x()) || (nodes.current().y() > bound.y())) { 
                trim.add(elts.current());
            }
                           }
    }
    m.remove(trim);  // Delete the out of bounds elements.
}


void Mesh::remove(const List<CountedObjPtr<Element> >& trim) { 
    for (ListIterator<CountedObjPtr<Element> > i(trim); i.more(); i.advance()) { 
                           element_table.remove(i.current());
    }
}


int main() {
    Mesh m;
    cin >> m;

    Number angle_threshold;
    cin >> angle_threshold;

    cout << "Before trim:" << endl;
    Boolean anglesOK = m.checkElementAngles(angle_threshold);

    trimTo(m, Point(8.5,5.5));

    cout << "After trim:" << endl;
    anglesOK = m.checkElementAngles(angle_threshold);

    return anglesOK ? EXIT_SUCCESS : EXIT_FAILURE;
}


Boolean Mesh::checkElementAngles(Number angle_threshold) const {
    Boolean anglesOK = Boolean::true;
    for (ElementsOfMesh elts(*this); elts.more(); elts.advance()) {
                           if (elts.current()->maxAngle() > angle_threshold) {
            cout << "Element " << *elts.current() << " has a large angle." << endl;
            anglesOK = Boolean::false;
                           }
    }
    return anglesOK;
}


Number Element::maxAngle() const {
    Number maxang = 0.0;
    for (NodesOfElement nodes(*this); nodes.more(); nodes.advance()) {
                           Number angle = nodes.current().angle(nodes.cwNeighbor(), nodes.ccwNeighbor());
                           if ( angle > maxang ) maxang = angle;
    }
    return maxang;
}


istream& operator>>(istream& instream, Mesh& m) {
    // Set sizes of node and element tables
    int nNodes;
    int nElements;
    instream >> nNodes >> nElements;
    NodeReader reader(nNodes, instream);
    //m.element_table.setSize(nElements);

    // Read elements
    for (int elementNum = 0; elementNum < nElements; elementNum++) {
                           Element* tmp = new Element;
                           reader >> *tmp;
                           m.element_table.add(tmp);
    }
    return instream;
}



void operator>>(NodeReader& reader, Element& e) {
    int nNodesInElement = reader.getSize();
    e.node_ptrs.setSize(nNodesInElement);
    for (int i = 0; i < nNodesInElement; i++) {
                           e.node_ptrs[i] = reader.getNode();
    }
}


ostream& operator<<(ostream& os, const Element& e) {
    os << "[ ";
    for (int i = 0; i < e.node_ptrs.numElts(); i++) {
                           os << *e.node_ptrs[i] << " ";
    }
    return os << "]";
}


NodeReader::NodeReader(int num_nodes, istream& instream) : 
    node_table(num_nodes), in(instream) {
    // Read nodes
    for (int nodeNum = 0; nodeNum < num_nodes; nodeNum++) {
                           node_table[nodeNum] = new Node;
                           instream >> *(node_table[nodeNum]);
    }
}

int NodeReader::getSize() {
    int size;
    in >> size;
    return size;
}


CountedObjPtr<Node> NodeReader::getNode() {
    int nodeNum;
    in >> nodeNum;
    return node_table[nodeNum];
}


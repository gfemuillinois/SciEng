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
#include "examples/ch6/SimpleArray.h"

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
    SimpleArray<Node*> node_ptrs;
};


class Mesh {
public:

    friend ElementsOfMesh; // Iterator over elements of a mesh
    friend NodesOfMesh;    // Iterator over nodes of a mesh

    friend istream& operator>>(istream&, Mesh&);
    friend NodeReader;

    Boolean checkElementAngles(Number angle_threshold) const;
private:
    SimpleArray<Node> node_table;
    SimpleArray<Element> element_table;
};


class NodeReader {
public:
    NodeReader(Mesh& m, istream& instream);
    int   getSize();
    Node* getNode();
private:
    Mesh& mesh;
    istream& in;
};


class ElementsOfMesh {
public:
    ElementsOfMesh(const Mesh& m) :
                           element_table(m.element_table), cur(m.element_table.numElts()-1) { }


    Boolean        more()    const { return cur >= 0;           }
    void           advance()       { --cur;                     }
    const Element& current() const { return element_table[cur]; }

private:
    const SimpleArray<Element>& element_table;
    int cur;
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


int main() {
    Mesh m;
    cin >> m;

    Number angle_threshold;
    cin >> angle_threshold;
    Boolean anglesOK = m.checkElementAngles(angle_threshold);

    return anglesOK ? EXIT_SUCCESS : EXIT_FAILURE;
}


Boolean Mesh::checkElementAngles(Number angle_threshold) const {
    Boolean anglesOK = Boolean::true;
    for (ElementsOfMesh elts(*this); elts.more(); elts.advance()) {
                           if (elts.current().maxAngle() > angle_threshold) {
            cout << "Element " << elts.current() << " has a large angle." << endl;
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
    m.node_table.setSize(nNodes);
    m.element_table.setSize(nElements);

    // Read nodes
    for (int nodeNum = 0; nodeNum < nNodes; nodeNum++) {
                           instream >> m.node_table[nodeNum];
    }

    // Read elements
    NodeReader reader(m, instream);
    for (int elementNum = 0; elementNum < nElements; elementNum++) {
                           reader >> m.element_table[elementNum];
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


NodeReader::NodeReader(Mesh& m, istream& instream) :
    mesh(m), in(instream) {}


int NodeReader::getSize() {
    int size;
    in >> size;
    return size;
}

Node* NodeReader::getNode() {
    int nodeNum;
    in >> nodeNum;
    return &mesh.node_table[nodeNum];
}


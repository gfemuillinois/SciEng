/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <cstdlib>
#include "SciEng/Boolean.h"
#include "examples/ch6/Point.h"
#include "examples/ch6/SimpleArray.h"

#include "examples/ch8/Element.h"

// Redefine EXIT_SUCCESS and EXIT_FAILURE.  When this program works it should return
// EXIT_FAILURE, but run-test in the Makefile tests for EXIT_SUCCESS.
#undef EXIT_SUCCESS
#undef EXIT_FAILURE
#define EXIT_SUCCESS 1
#define EXIT_FAILURE 0


typedef Point Node;


class Mesh {
public:
    Boolean checkElementAngles(Number angle_threshold) const;
    Number  maxAngle(const Element& e) const;
    int numNodes() const;
    int numElements() const;
    friend istream& operator>>(istream&, Mesh&);
private:
    SimpleArray<Node> node_table;
    SimpleArray<Element> element_table;
};


int Mesh::numNodes() const { return node_table.numElts(); }
int Mesh::numElements() const { return element_table.numElts(); }

Boolean Mesh::checkElementAngles(Number angle_threshold) const {
    Boolean anglesOK = Boolean::IsTrue;
    for (int eltNum = 0; eltNum < numElements(); eltNum++) {
        const Element& e = element_table[eltNum]; // e is an alias for element # eltNum
        if (maxAngle(e) > angle_threshold) {
            cout << "Element [ ";
            for (int i = 0; i < e.numNodes(); i++) cout << node_table[e[i]] << " ";
            cout << "] has a large angle." << endl;
            anglesOK = Boolean::IsFalse;
        }
    }
    return anglesOK;
}


Number Mesh::maxAngle(const Element& e) const {
    Number maxang = 0.0;
    int numNodes = e.numNodes();
    for (int i = 0; i < numNodes; i++) {

        int ccwNodeNum = (i + 1) % numNodes;
        int cwNodeNum  = (i + numNodes - 1) % numNodes;

        Number angle = 
            node_table[e[i]].angle(node_table[e[cwNodeNum]], node_table[e[ccwNodeNum]]);
        if ( angle > maxang ) maxang = angle;
    }
    return maxang;
}


istream& operator>>(istream& instream, Mesh& m) {
    int nNodes;
    int nElements;
    instream >> nNodes >> nElements;
    m.node_table.setSize(nNodes);
    m.element_table.setSize(nElements);
    for (int nodeNum = 0; nodeNum < nNodes; nodeNum++) {
        instream >> m.node_table[nodeNum];
    }
    for (int elementNum = 0; elementNum < nElements; elementNum++) {
        instream >> m.element_table[elementNum];
    }
    return instream;
}



int main() {
    Mesh m;
    cin >> m;

    Number angle_threshold;
    cin >> angle_threshold;
    Boolean anglesOK = m.checkElementAngles(angle_threshold);

    return anglesOK ? EXIT_SUCCESS : EXIT_FAILURE;
}


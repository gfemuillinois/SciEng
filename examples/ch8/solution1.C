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


typedef SimpleArray<int> Element;


Number
maxAngle(const Element& e, const SimpleArray<Point>& nodeTable) {
    Number maxang = 0.0;
    int numNodes = e.numElts();
    for (int i = 0; i < numNodes; i++) {

        int ccwNodeNum = (i + 1) % numNodes;
        int cwNodeNum  = (i + numNodes - 1) % numNodes;

        Number angle = 
            nodeTable[e[i]].angle(nodeTable[e[cwNodeNum]], nodeTable[e[ccwNodeNum]]);
        if ( angle > maxang ) maxang = angle;
    }
    return maxang;
}



int main() {

    // Read sizes and create tables
    int numNodes;
    int numElements;
    cin >> numNodes >> numElements;

    SimpleArray<Point> nodeTable(numNodes);
    SimpleArray<Element> elementTable(numElements);

    // Read node data
    for (int nodeNum = 0; nodeNum < numNodes; nodeNum++) {
        cin >> nodeTable[nodeNum];
    }

    // Read element data
    for (int eltNum = 0; eltNum < numElements; eltNum++) {
        Element& e = elementTable[eltNum]; // e is an alias for element # eltNum
        int elementSize;
        cin >> elementSize;
        e.setSize(elementSize);
        for (int i = 0; i < elementSize; i++) cin >> e[i];
    }

    // Read maximum angle threshold and check elements
    Number angle_threshold;
    cin >> angle_threshold;
    Boolean anglesOK = Boolean::IsTrue;
    for (int eltNum = 0; eltNum < numElements; eltNum++) {
        Element& e = elementTable[eltNum]; // e is an alias for element # eltNum
        if (maxAngle(e, nodeTable) > angle_threshold) {
            cout << "Element [ ";
            for (int i = 0; i < e.numElts(); i++) 
	      cout << nodeTable[e[i]] << " ";
            cout << "] has a large angle." << endl;
            anglesOK = Boolean::IsFalse;
        }
    }
    return anglesOK ? EXIT_SUCCESS : EXIT_FAILURE;
}
  


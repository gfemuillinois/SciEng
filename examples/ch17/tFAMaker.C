/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch17/FAMaker.h"
#include <iostream>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << argv[0] << ": One command line argument is expected; ";
        cerr << "it should contain an expression to evaluate" << endl;
        return 1;
    }

    FAMaker parser(argv[1]);
    FunctionalAlgebra<double> f = parser.function();
    double x;
    while (cin >> x) cout << argv[1] << "(" << x << ") = " << f(x) << endl;
    return 0;
}


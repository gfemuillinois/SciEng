/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>

#include "DataModeling/LinearizationIterator.h"
#include "DataModeling/DampedSVDIteratedEquations.h"
#include "DataModeling/FormedPhysicalData.h"
#include "DataModeling/DualGaussianModel.h"
#include "SciEng/String.h"


int main(int argc, char* argv[]) {


    int    max_iters   = 10;
    double convergence = NumericalLimits<float>::epsilon;


    if (argc > 1) max_iters = String(argv[1]).strtol();
    if (argc > 2) convergence = String(argv[2]).strtod();

    // A problem from "Numerical Recipes Example Book",
    // W. Vetterling, S. Teukolsky, W. Press, and B. Flannery,
    // Cambridge University Press, 1988.

    DualGaussianModel<double> model(4.5, 2.2, 2.8, 2.5, 4.9, 2.8);
    FormedPhysicalData data(cin, 100);
    DampedSVDIteratedEquations<double> eqns(data, model);

    LinearizationIterator<double> solver(eqns, model.parameters(), max_iters, convergence);
    solver.solve();

    cout << solver.current() << endl;

    return EXIT_SUCCESS;
}


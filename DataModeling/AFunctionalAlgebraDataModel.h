/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AFunctionalAlgebraDataModelH
#define AFunctionalAlgebraDataModelH

#include "DataModeling/FunctionalAlgebraDataModel.h"

                             

class AFunctionalAlgebraDataModel : 
    public FunctionalAlgebraDataModel<double> {
public:
    AFunctionalAlgebraDataModel(): 
        FunctionalAlgebraDataModel<double>(6),

        g1      (5.0,2.0,3.0),   // A standard problem from "Numerical Recipes Example Book",
        g1_guess(4.5,2.2,2.8),   // W. Vetterling, S. Teukolsky, W. Press, and B. Flannery,
        g2      (2.0,5.0,3.0),   // Cambridge University Press, 1988.
        g2_guess(2.5,4.9,2.8),

        noise_spread(0.001),
        idum(-911) {
    }

private:     // Values for standard test case.
    class GaussianData {  
    public:
        GaussianData(double a, double m, double w):
            area(a), mean(m), width(w) {
        }
    public:
        double area;
        double mean;
        double width;
    };

    GaussianData g1;
    GaussianData g1_guess;

    GaussianData g2;
    GaussianData g2_guess;

    double noise_spread;
    int idum;
};


#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef PeakModelParametersH
#define PeakModelParametersH

#include "DataModeling/ModelParameter.h"


template<class RallT>
class PeakModelParameters3d {  
public:
    PeakModelParameters3d(double a, double m, double w):
        the_area(a), the_mean(m), the_width(w) {
    }


    ModelParameter<RallT> area()  const { return the_area; }
    ModelParameter<RallT> mean()  const { return the_mean; }
    ModelParameter<RallT> width() const { return the_width; }


private:
    ModelParameter<RallT>  the_area;
    ModelParameter<RallT>  the_mean;
    ModelParameter<RallT>  the_width;
};


#endif

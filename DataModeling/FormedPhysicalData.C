/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <fstream>
#include "DataModeling/FormedPhysicalData.h"
#include "SciEng/String.h"


FormedPhysicalData::
FormedPhysicalData(std::istream& ns, unsigned int num_data_pts) : 
    x(num_data_pts),
    y(num_data_pts),
    sigma(num_data_pts) {
    unsigned int n;
    for (n = 0; ns && n < num_data_pts; n++) { 
        ns >> x(n) >> y(n) >> sigma(n);
    }
    if (n < num_data_pts) throw TooLittleDataInput();
}



FormedPhysicalData::TooLittleDataInput::
TooLittleDataInput() { };

String
FormedPhysicalData::TooLittleDataInput::
message() const {
  String s;
  s << "Too little data input to FormedPhysicalData\n"; // << endl;
  return s;
}

#include "Array/arrayCopy.h"
FormedPhysicalData::FormedPhysicalData(
    const ConstArray1d<double>& x_in,
    const ConstArray1d<double>& y_in,
    const ConstArray1d<double>& sigma_in
  ) :
    x(x_in.numElts()),
    y(y_in.numElts()),
    sigma(sigma_in.numElts()) {
    if (
      (x.numElts() != y.numElts()) ||
      (x.numElts() != sigma.numElts())
      ) {
        throw TooLittleDataInput();
    }
      
    arrayCopy(x, x_in);
    arrayCopy(y, y_in);
    arrayCopy(sigma, sigma_in);
}


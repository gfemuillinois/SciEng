/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Algebra/ComplexFloat.h"


class LinearFractionalTrans {
public:
    LinearFractionalTrans(ComplexFloat a, ComplexFloat b, ComplexFloat c, ComplexFloat d) :
        _a(a), _b(b), _c(c), _d(d) {}
    ComplexFloat operator()(ComplexFloat z) const {
        return (_a * z + _b) / (_c * z + _d);
    }
private:
    ComplexFloat _a, _b, _c, _d;
};


int main() {
  LinearFractionalTrans t(ComplexFloat(2,-4), ComplexFloat(2,4), ComplexFloat(1,-1), ComplexFloat(1,1));
  cout << t(1) << endl;
  cout << t(ComplexFloat(0,1)) << endl;
  cout << t(-1) << endl;
  return 0;
}

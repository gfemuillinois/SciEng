/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <math.h>
#include "Vector/ConcreteVector3d.h"


ostream& operator<<(ostream& os, const ConcreteVector3d& v) {
    return os << '[' << v.x() << ',' << v.y() << ',' << v.z() << ']';
}



istream& operator>>(istream& is, ConcreteVector3d& v) {
    double x, y, z;
    char c = 0;
    is >> c;
    if (c == '[') {
        is >> x >> c;
        if (c != ',') is.clear(ios::badbit);
        is >> y >> c;
        if (c != ',') is.clear(ios::badbit);
        is >> z >> c;
        if (c != ']') is.clear(ios::badbit);
    }
    else is.clear(ios::badbit);

    if (is) { v.x() = x; v.y() = y; v.z() = z; }
    return is;
}



ConcreteVector3d& ConcreteVector3d::operator*=(const ConcreteVector3d& b){ 

  // this = this x b
  // i.e., * is cross-product operation.

    double x_component = y()*b.z() - z()*b.y();
    double y_component = z()*b.x() - x()*b.z();
    double z_component = x()*b.y() - y()*b.x();
    x() = x_component;
    y() = y_component;
    z() = z_component;
    return *this;
}


double ConcreteVector3d::dot(const ConcreteVector3d& b) const { 
  return x()*b.x() + y()*b.y() + z()*b.z(); 
}

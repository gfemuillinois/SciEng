/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteVector3dH
#define ConcreteVector3dH

#include "SciEng/Subscript.h"
#include "Algebra/LinearAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"

class ostream;
class istream;


class ConcreteVector3d :
    public LinearAlgebraCategory< ConcreteVector3d, double >,
    public MetricSpaceCategory< ConcreteVector3d, double > {
public:
    ConcreteVector3d(double x, double y, double z) { a[0]=x; a[1]=y; a[2]=z; }
    ConcreteVector3d() { }
    ConcreteVector3d(const ConcreteVector3d& cv) { 
        a[0] = cv.a[0]; a[1] = cv.a[1]; a[2] = cv.a[2]; 
    }


    double x() const { return a[0]; }
    double y() const { return a[1]; }
    double z() const { return a[2]; }



    double& x() { return a[0]; }
    double& y() { return a[1]; }
    double& z() { return a[2]; }


    // User-must-define function for MetricSpaceCategory
    double dot(const ConcreteVector3d& b) const;

    // User-must-define functions for LinearAlgebraCategory
    ConcreteVector3d& operator*=(const ConcreteVector3d& rhs);
    inline ConcreteVector3d& operator+=(const ConcreteVector3d& rhs);
    inline ConcreteVector3d& operator-=(const ConcreteVector3d& rhs);
    inline ConcreteVector3d& setToZero();
    inline ConcreteVector3d& operator*=(double);
    inline ConcreteVector3d& operator/=(double);
private:
    double a[3];
};



extern ostream& operator<<(ostream& os, const ConcreteVector3d& v);



extern istream& operator>>(istream& os, ConcreteVector3d& v);



inline ConcreteVector3d& ConcreteVector3d::operator+=(const ConcreteVector3d& rhs) {
    a[0] += rhs.a[0];
    a[1] += rhs.a[1];
    a[2] += rhs.a[2];
    return *this;
}


inline ConcreteVector3d& ConcreteVector3d::operator-=(const ConcreteVector3d& rhs){
  a[0] -= rhs.a[0];
  a[1] -= rhs.a[1];
  a[2] -= rhs.a[2];
  return *this;
}
inline ConcreteVector3d& ConcreteVector3d::setToZero(){
  a[0] = 0.;
  a[1] = 0.;
  a[2] = 0.;
  return *this;
}

inline ConcreteVector3d& ConcreteVector3d::operator*=(double rhs) {
    a[0] *= rhs;
    a[1] *= rhs;
    a[2] *= rhs;
    return *this;
}

inline ConcreteVector3d& ConcreteVector3d::operator/=(double rhs){
  a[0] /= rhs;
  a[1] /= rhs;
  a[2] /= rhs;
  return *this;
}

#endif

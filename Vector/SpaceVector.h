/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SpaceVectorH
#define SpaceVectorH

#include "Vector/RigidArithmetic.h"
#include <math.h>

class SpaceVector : public RigidArithmetic1d<double, 3ul> {
  public:
    SpaceVector(){
    (*this)(0)=0.;
    (*this)(1)=0.;
    (*this)(2)=0.;
    }
    SpaceVector(double x, double y, double z){
    (*this)(0)=x;
    (*this)(1)=y;
    (*this)(2)=z;
    }
    void operator=(const SpaceVector& s){
    (*this)(0)=s(0);
    (*this)(1)=s(1);
    (*this)(2)=s(2);
    }
    double& x(){return elts[0];}
    double& y(){return elts[1];}
    double& z(){return elts[2];}
    double dot(const SpaceVector& v) const {return x()*v.x() + y()*v.y() + z()*v.z();}
    double norm(){return sqrt(this->dot(*this));}
};
#endif

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "AutoDeriv/ElasticRall1d.h"
#include "AutoDeriv/RigidRall1d.h"
#include <iostream.h>

template<class T>
T lbRallEq2(const T& x){
  return ( x * x + T(2.) * x - T(3.) ) / ( x + T(2.) );
}

int main() {
  cout << "Testing Rall Numbers...." << endl;
  cout << " Equation (2) from L. B. Rall, The Arithmetic of Differentiation," << endl;
  cout << " Mathematics Magazine, 59 (1986) 275." << endl;
  
  cout << " Template expansion for type double" << endl;
  cout << lbRallEq2(3.0) << endl;
  {
    cout << " Evaluation of unit vector type ElasticArithmetic1d" << endl;
    typedef ElasticRall1d<double> RallT;
    RallT x(3.0,0,1);
    cout << x << endl;
  
    cout << " Template expansion for type ElasticRall1d " << endl;
    cout << lbRallEq2(x) << endl;
    cout <<"Result given by L. B. Rall: (" <<  12./5. << "," << 28./25. << ")" << endl;
  }
  {
    cout << " Evaluation of unit vector type RigidRall1d " << endl;
    typedef RigidRall1d<double,1> RallT;
    RallT x(3.0,0,1);
    cout << x << endl;
  
    cout << " Template expansion for type RigidRall1d " << endl;
    cout << lbRallEq2(x) << endl;
    cout <<"Result given by L. B. Rall: (" <<  12./5. << "," << 28./25. << ")" << endl;
  }
  {
    cout << "Start tRall--output" << endl;

    typedef RigidRall1d<double, 1> RallT;
    RallT x(3.0, 0, 1);

cout << "(x^2 + 2x - 3)/(x + 2) at x=3.0 is " 
     << ( x * x + 2.0 * x - 3.0 ) / ( x + 2.0 )
     << endl;


    cout << "end tRall--output" << endl;
    cout << "Result given by L. B. Rall: (" <<  12./5. << "," << 28./25. << ")" << endl;
  }
  cout << endl;
  return 0;
}



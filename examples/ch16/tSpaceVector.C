/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <strstream.h>
#include "Vector/ConcreteVector3d.h"

double circle_radius(ConcreteVector3d a, ConcreteVector3d b, ConcreteVector3d c) {
  double r;


  r = ( (a-c).norm() * (b-c).norm() * (a-b).norm() ) /
      ( 2.0 * ((a-c) * (b-c)).norm() );


  return r;
}

int main(int argc, char** argv){
  ConcreteVector3d v1(0, 0, 0);
  ConcreteVector3d v2(1, 2, 3);
  ConcreteVector3d v3(4, 5, 6);
  double d=v1.dot(v2);
  double d2=v2.dot(v2);
  double d3=v2.dot(v2+v2);
  if (d != 0 || d2 != 14 || d3 != 28) { cerr << "Dot products failed" << endl; exit(1); }
  if (sizeof(ConcreteVector3d) != 3*sizeof(double)){
    cerr << " sizeof(ConcreteVector3d)=" << sizeof(ConcreteVector3d) << endl;
    }

  cout << v2 + v3 << endl;
  cout << v2 - v3 << endl;
  cout << v2 * v3 << endl;
  cout << v3 * v2 << endl;
  cout << v2 * 3.0 << endl;
  cout << v2 / 3.0 << endl;
  cout << v2 * 4 << endl;
  cout << pow(v2, 2) << endl;
  cout << -v3 << endl;
  ConcreteVector3d v4(10, 20, 0);
  ConcreteVector3d v5(0, 0, 1);
  cout << v4.angle(v5) << endl;

  ConcreteVector3d a(0,1,0);
  ConcreteVector3d b(0,-1,0);
  ConcreteVector3d c(1,0,0);
  cout << circle_radius(a, b, c) << endl;

  // Test input operator
  istrstream is("[1,2,3]  [4    , 5, 6] [7 , 8,9   ] [ 10, 11 12 ]");
  is >> a >> b >> c;
  if (!is) { cerr << ">> failed on correct input" << endl; exit(1); }
  cout << a << b << c << endl;
  is >> a;
  if (is)  { cerr << ">> failed to detect bad input" << endl; exit(1); }
  cout << a << endl;
  istrstream is1("13, 14, 15");
  is1 >> a;
  if (is)  { cerr << ">> failed to detect bad input" << endl; exit(1); }
  cout << a << endl;
  return 0;
}
  

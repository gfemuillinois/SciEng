//
// Tests for ConcreteRigidArray
//

#include <iostream>
#include <cstdlib>

#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"
#include "Array/ConcreteRigidArray3d.h"

using std::cout;
using std::endl;

int main() {

  ConcreteRigidArray1d<float, 5> ra1d, ra1d_;     // 5x1 array of floats

  ra1d = 1.0;
  cout << "ra1d = " << ra1d << endl;

  ra1d_ = ra1d;
  ra1d = 2.0;
  cout << "ra1d = " << ra1d << endl;
  cout << "ra1d_ = " << ra1d_ << endl;

  ConcreteRigidArray2d<float, 3, 4> ra2d, ra2d_;  // 3x4 array of floats

  ra2d = 1.0;
  cout << "ra2d = " << ra2d << endl;

  ra2d_ = ra2d;
  ra2d = 2.0;
  cout << "ra2d = " << ra2d << endl;
  cout << "ra2d_ = " << ra2d_ << endl;

  ConcreteRigidArray3d<int, 4, 3, 2> ra3d, ra3d_;  // 4x3x2 array of ints

  ra3d = 3;
  cout << "ra3d = " << ra3d << endl;

  ra3d_ = ra3d;
  ra3d = 2;
  cout << "ra3d = " << ra3d << endl;
  cout << "ra3d_ = " << ra3d_ << endl;

  return EXIT_SUCCESS;

}


//
// Test for several classes
//

#include <iostream>

#include "SubscriptArray.h"
#include "ArrayIterator1d.h"
#include "ConcreteArrayIterator.h"
#include "ConcreteArrayShape.h"
#include "ConcreteArray1d.h"
#include "ConcreteFormedArray1d.h"

int main() {

  cout << "Tests for object in Array dir: " << endl;

  //  using SciEngLib::SubscriptArray;
  //  using SciEngLib::ConcreteArray1d;

  SubscriptArray<1> subscr(10);
  ConcreteArrayShape<1> arr_shp( subscr );

  ConcreteArray1d< arr_shp, double > cfa1d;

}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ConcreteFortranArray2d.h"
#include "Array/FormedArray2d.h"
#include <iostream.h>

int main() {



int i = 5;             // Object, value 5.
int &ir = i;           // non-const reference to i.
const int& cir = i;    // const reference to i.
const int& cir1 = ir;  // const reference to i.
/*
int& ir1 = cir;        // WRONG: const int& can't be converted to int&
*/
ir = 6;                // Alter object i


{

typedef ConcreteFortranArray2d<double> Array; // Abbreviation
Array a(3, 4);
ConcreteArray2dRef<Array::SubscriptorT, Array::EltT> ar = a;
ar = 10.0;

}
{

ConcreteFortranArray2d<double> a(3, 4);
a[1] = 1.0;

a[0] = 0;
a[2] = 2;
cout << a << endl;
if (sizeof(a[1]) != sizeof(double*) + 2 * sizeof(Subscript)) {
  cout << "Surprising size for a projection: " << sizeof(a[1]) << endl;
}
}

FormedArray2d<double> a(3, 4);
a[1] = 1;

a[0] = 0;
a[2] = 2;
cout << a << endl;
return 0;
}



typedef ConcreteFortranArray2d<double>                       Array;  // Abbreviations
typedef ConcreteArray2dRef<Array::SubscriptorT, Array::EltT> Ref;


Ref dangle() {
    Array a(3, 4);
    return Ref(a); // Creates dangling reference
}


static void f() {

  Subscript n0;  // Upper bound on s0
  Subscript n1;  // Upper bound on s1
  // ... set n0 and n1
  n0 = n1 = 2;
  for (Subscript s0 = 0; s0 < n0; s0++) {
    for (Subscript s1 = 0; s1 < n1; s1++) {
        // ... do something ...
    }
  }

}

static void g() {
  Subscript n0 = 2;
  Subscript n1 = 2;

  for (ArrayStepper2d i(n0, n1); i.more(); i.advance()) {
    // ... do something ...
  }

}

static void h() {

  ConcreteFormedArray2d<int> a(3, 4);
  // ...
  for (ArrayBrowser2d< ConcreteFormedArray2d<int> > i(a); i.more(); i.advance()) {
    cout << i.current() << endl;
  }

}

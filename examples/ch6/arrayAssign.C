/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Array {
public:

    Array(int n);                    // Create n element array of int's
    Array(const Array&);             // Copy array
    Array& operator=(const Array&);  // Assign array

    // ...
};
// ...

Array::Array(int n) { cout << "constructing, n = " << n << endl; }
Array::Array(const Array&) { cout << "copying" << endl; }
Array& Array::operator=(const Array&) { cout << "assigning" << endl; return *this; }

int main() {

  Array a(5);
  a = 5;

  return 0;
}

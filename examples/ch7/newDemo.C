/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "examples/ch7/Rational.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

int* p = new int;


int* q = new int(3);


Rational* r = new Rational(8, 9);


// Create array of int's with size determined at runtime
int num_elements;
cin >> num_elements;
int* qa = new int[num_elements];


delete p;
delete q;
delete r;


delete [] qa;

  return 0;
}

Rational::Rational(int, int) {}

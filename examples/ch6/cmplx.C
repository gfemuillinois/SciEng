/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class Complex {
public:
    Complex(float = 0.0);
    Complex(float, float);
    Complex operator+(const Complex&) const;
    // ...
};

void f() {

  Complex a;
  Complex b;

  b = a + 3.0; // 3.0 is converted to Complex(3.0)
/*
  b = 3.0 + b; // WRONG: + not allowed between double and Complex


*/
}

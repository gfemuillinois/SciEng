/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef BOOLEANH
#define BOOLEANH

class ostream;
class istream;

//namespace SciEngLib{

class Boolean {
public:
    // Constants
    enum constants { IsFalse = 0, IsTrue = 1 };

    // Construction.

  Boolean()                      {}   // Construct uninitialized.
  Boolean(int i) :    v(i != 0)  {}   // Construct and initialize to (i != 0).
  explicit Boolean(float f) :  v(f != 0)  {}   // Construct and initialize to (f != 0).
  explicit Boolean(double d) : v(d != 0)  {}   // Construct and initialize to (d != 0).
  explicit Boolean(void* p) :  v(p != 0)  {}   // Construct and initialize to (p != 0).

    // Conversion.
    operator int() const{ return v; }   // To allow "if (boolean-value)..."

    // Negation.
    Boolean operator!() const { return !v; }


private:
    char v;
};


  // I/O

ostream& operator<<(ostream& s, Boolean  b);
istream& operator>>(istream& s, Boolean& b);

//}

#endif

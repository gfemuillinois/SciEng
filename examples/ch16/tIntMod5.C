/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "Algebra/SemiGroupCategory.h"

class IntMod5 : public SemiGroupCategory<IntMod5> {
public:
  IntMod5(int v = 0)        { val = v % 5; }
  IntMod5(const IntMod5& x) { val = x.val; }

  IntMod5& operator*=(const IntMod5& rhs) {
    val = (val * rhs.val) % 5;
    return *this;
  }
  friend ostream& operator<<(ostream& s, const IntMod5& x) {
    return s << x.val;
  }

private:
  int val;
};


int main() {    
    IntMod5 a = 2;
    IntMod5 b = 4;
    cout << a * b << " " << a.pow(4) << " " << a << " " << pow(b, 3) << endl;
    return 0;
};




#ifndef TINTMOD5H
#define TINTMOD5H

#include <iostream>
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

#endif


#ifndef TGROUPD3H
#define TGROUPD3H

#include <iostream>

#include "Algebra/GroupCategory.h"

class GroupD3 :
  public GroupCategory<GroupD3> { // Dihedral group of degree 3.
public:

  enum sym_op { R0, R120, R240, M1, M2, M3 };

  GroupD3(sym_op so = R0) { val = so; }
  GroupD3(const GroupD3& x) {val = x.val; }
  GroupD3& operator*=(const GroupD3& rhs){ val = mult_tab[val][rhs.val]; return *this;}
  GroupD3& operator/=(const GroupD3& rhs){ val = inv_tab[rhs.val]; return *this;}
  GroupD3& setToOne(){ val = R0; return *this; }
  friend ostream& operator<<(ostream& s, const GroupD3& x);

private:
  static sym_op mult_tab[6][6];
  static sym_op inv_tab[6];
  static char*  name_tab[6];
  sym_op val;
};

#endif

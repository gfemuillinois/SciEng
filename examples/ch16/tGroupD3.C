/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include "tGroupD3.h"

ostream& operator<<(ostream& s, const GroupD3& x) {
  return s << GroupD3::name_tab[x.val];
}

GroupD3::sym_op GroupD3::mult_tab[6][6] = {
                               { R0  , R120, R240, M1  , M2  , M3   },
                               { R120, R240, R0  , M3  , M1  , M2   },
                               { R240, R0  , R120, M2  , M3  , M1   },
                               { M1  , M2  , M3  , R0  , R120, R240 },
                               { M2  , M3  , M1  , R240, R0  , R120 },
                               { M3  , M1  , M2  , R120, R240, R0   }
                              };

GroupD3::sym_op GroupD3::inv_tab[6] = { R0, R240, R120, M1, M2, M3 };

char* GroupD3::name_tab[6] = { "R0", "R240", "R120", "M1", "M2", "M3" };

int main() {

    cout << GroupD3(GroupD3::R240) * GroupD3(GroupD3::M1)
         << " " << pow(GroupD3(GroupD3::M2), 4) << endl;

    return 0;
}


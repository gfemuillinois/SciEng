/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream>
#include "SciEng/String.h"
using std::cout;
using std::cin;
using std::endl;

int main() {

  String s1("abcd");

  s1 += "efg";           // Right operand converted; result: abcdefg
  String s2 = "xyz" + s1;// Left operand converted;  result: xyzabcdefg
  String s3 = s2 + "123";// Right operand converted; result: xyzabcdefg123


  if (s1 != "abcdefg" || s2 != "xyzabcdefg" || s3 != "xyzabcdefg123") {
    cout << "\nunexpected result" << endl;
    return 1;
  }
  return 0;
}

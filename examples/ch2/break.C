/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
int main() {

  int x;
  while (std::cin >> x) {
    if (x < 0) {
      std::cout << "Negative number " << x << " read" << std::endl;
      break;
    }
    // ... processing of input goes here
  }

  return 0;
}

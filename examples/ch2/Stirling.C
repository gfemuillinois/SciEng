/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <stdlib.h>


int stirling(int n, int k) {
    if (n < k) return 0;
    if (k == 0 && n > 0) return 0;
    if (n == k) return 1;
    return k * stirling(n-1, k) + stirling(n-1, k-1);
}


int main() {
  int n, k;
  while (std::cin >> n >> k) {
    std::cout << stirling(n, k) << std::endl;
  }
  return 0;
}


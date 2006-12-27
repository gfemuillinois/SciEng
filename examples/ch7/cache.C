/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

float f(float x) { 
  cout << "f called" << endl;
  return 2 * x;
}


extern float f(float); // Expensive computation

float remembers(float x) {
    static int first_time = 1;
    static float previous_x;
    static float previous_result;

    if (first_time || x != previous_x) {
        first_time = 0;
        previous_x = x;
        previous_result = f(x);
    }
    return previous_result;
}


int main() {
  cout << remembers(1) << endl;
  cout << remembers(1) << endl;
  cout << remembers(2) << endl;
  cout << remembers(2) << endl;
  cout << remembers(3) << endl;
  return 0;
}

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

int main() {


int i = 3;        // Variable
int& ir = i;      // Reference to variable i



cout << ir << endl;
ir = 4;


cout << ir << endl;


const float pi = 3.14159;
const float& unit_circle_area = pi;


float x;
const float& xr = x;
x = 5.0;

return 0;
}

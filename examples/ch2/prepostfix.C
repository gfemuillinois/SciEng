/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
int main() {


int i = 1;
cout << i << ", ";         // Print i
cout << (++i) << ", ";     // Increment i, then print its new value
cout << i << ", ";         // Print i
cout << (i++) << ", ";     // Print i's old value, then increment i
cout << i << endl;         // Print i


return 0;   
}

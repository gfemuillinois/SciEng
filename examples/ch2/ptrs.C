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

int* p;


int i = 3;
p = &i;


int j = 4;
p = &j;


cout << *p << endl;


*p = 5;
cout << *p << " " << i << " " << j << endl;


if (p != 0) {
    cout << "Pointer p points at " << *p << endl;
} 

return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <iomanip.h>
int main() {

char command;
enum commandFlags {enable = 0x01, pulse = 0x02, tone = 0x04, reset = 0x08 };
command = (enable | tone);

cout.setf(ios::showbase);
cout.setf(ios::hex, ios::basefield);
cout << int(command) << endl;
return 0;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>


extern void f(float);
extern void f(double);
template<class T> extern void f(T);

int main() {

f(1);
float x = 1.0;
f(x);
f('a');
f(1.0);

return 0;
}

void f(float) { cout << "f(float)" << endl; }
void f(double) { cout << "f(double)" << endl; }
template<class T> extern void f(T) { cout << "f(T)" << endl; }

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

void swap(int& i1, int& i2) {
    // Swap arguments
    int temp = i1;
    i1 = i2;
    i2 = temp;
}



void f(int i, float x, float* a) {
    i = 100;
    x = 101.0;
    a[0] = 0.0;
}

int main() {


int j = 1;
int k = 2;
float y[] = {3.0, 4.0, 5.0};
// ...
f(j, k, y);

cout << j << " " << k << endl;
cout << y[0] << " " << y[1] << " " << y[2] << endl;


int i = j;
float x = k;
float* a = y;

i = 100;
x = 101.0;
a[0] = 0.0;



int c = 3;
int d = 4;
swap(c, d);
// c == 4 and d == 3

if (c != 4 || d != 3) return 1;
return 0;
}

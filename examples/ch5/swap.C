/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

int order(int& i1, int& i2, int& i3) {
    // Rearrange arguments in ascending order.  Return maximum value.
    if (i1 > i2) { int temp = i1; i1 = i2; i2 = temp; }
    if (i2 > i3) { int temp = i2; i2 = i3; i3 = temp; }
    if (i1 > i2) { int temp = i1; i1 = i2; i2 = temp; }
    return i3;
}


int main() {
#ifdef COMPILE_BAD

int x = 3;
int z = 4;
order(x, 2, z);
float y = 5;
order(x, y, z);

#endif

int a = 1;
int b = 2;
int c = -8;
order(a, b, c);

if (a == -8 && b == 1 && c == 2) return 0;
else return 1;
}


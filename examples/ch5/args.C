/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include "Array/ConcreteFormedArray1d.h"

// Change name to match what is described in the text
#define SimpleArray1d ConcreteFormedArray1d


extern double exp(int y);
extern double exp(double y);

double exp(int) { return 1; }  // Used only to check overloading


float s(float a, float b) {
    a = b;
    return a * b;
}


extern int index_of_min(const SimpleArray1d<float>& a);


int index_of_min(const SimpleArray1d<float>& a) {

    float min_val = a[0]; // Minimum value found thus far
    int   min_idx = 0;    // Index of minimum value found thus far

    for (int i = 1; i < a.numElts(); i++) {
        if (a[i] < min_val) {
            min_idx = i;
            min_val = a[i];
        }
    }
    return min_idx;
}


float& min_elt(SimpleArray1d<float>& a) {
    return a[ index_of_min(a) ];
}


const float& min_elt(const SimpleArray1d<float>& a) {
    return a[ index_of_min(a) ];
}


extern float f();


extern float f(void);


float f() {
    // ...
    return 1;
}


int main() {
SimpleArray1d<float> y(4); y[0] = -3; y[1] = 3; y[2] = -100; y[3] = -200;
const SimpleArray1d<float>& yc = y;
if (index_of_min(y) != 3) return 1;
if (min_elt(y) != -200) return 1;
if (min_elt(yc) != -200) return 1;
y[0] = -1000;
if (index_of_min(y) != 0) return 1;
if (min_elt(y) != -1000) return 1;
y[1] = -2000;
if (index_of_min(y) != 1) return 1;
if (min_elt(y) != -2000) return 1;

SimpleArray1d<float> z(4);
z[0] = -3; z[1] = 3; z[2] = -100; z[3] = -200;
// ...
min_elt(z) = 0;

if (z[3] != 0) return 1;

float b = 4;


float x = 12.1;
s(x, 4);

if (x != float(12.1)) return 1;
x = b;  // suppress b not used compiler warning

// Check exp overloading
if (exp(short(1)) != 1 || exp(1) != 1 || exp(char(1)) != 1)  return 1;
if (exp(float(1)) == 1 || exp(double(1)) == 1) return 1;

return 0;
}

#ifdef COMPILE_BAD

double& g() {
    double x;
    // ...
    return x;  // WRONG: reference to local variable returned
}

#endif


extern void f2(int, float);
extern void f2(int, double);

void f2(int, double) {}
void f2(int, float) {}
void foo() {

double d = 2.0;
f2(1, d);    // Calls f(int, double)

#ifdef COMPILE_BAD

f2(1, 2);    // WRONG: ambiguous

#endif
}

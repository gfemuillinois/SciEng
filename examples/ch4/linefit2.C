/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream>
#include "examples/ch4/SimpleArray.h"
using std::cout;
using std::cin;
using std::endl;

void linefit() {
    // Create arrays with the desired number of elements
    int n;  
    cout << "Enter Number of data points:  "; cin >> n;
    SimpleArray<float> x(n);
    SimpleArray<float> y(n);

    // Read the data points

    cout << "Enter Data Points x[.] y[.] " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // ... same as before ...
    double sx  = 0.0, sy  = 0.0;
    {for (int i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
    }}

    // Compute coefficients
    double sx_over_n = sx / n;
    double stt = 0.0, b = 0.0;
    {for (int i = 0; i < n; i++) {
        double ti = x[i] - sx_over_n;

        stt += ti * ti;
        b   += ti * y[i];

    }}
    b /= stt;
    double a = (sy - sx * b) / n;

    cout << "Coeficients:" << endl;
    cout << " a = " << a << " " << " b = " << b << endl;
}


int main() {
  linefit();
  return 0;
}

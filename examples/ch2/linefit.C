/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include <iostream.h>

void linefit() {
    // Create arrays with the desired number of elements
    int n;  
    cin >> n;
    float* const x = new float[n];
    float* const y = new float[n];


    // Read the data points
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Accumulate sums Sx and Sy in double precision
    double sx  = 0.0;
    double sy  = 0.0;
    for (i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
    }

    // Compute coefficients
    double sx_over_n = sx / n;
    double stt = 0.0;
    double  b = 0.0;
    for (i = 0; i < n; i++) {
        double ti = x[i] - sx_over_n;

        stt += ti * ti;
        b   += ti * y[i];

    }
    b /= stt;
    double a = (sy - sx * b) / n;


    delete [] x;
    delete [] y;



    cout << a << " " << b << endl;
}


int main() {
  linefit();
  return 0;
}

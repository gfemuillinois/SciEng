/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

extern double g(const float y[]);

#ifdef BAD_COMPILE
void double g(const float y[]) {
  y[1] = 5.;
  return 0;
}
#endif

double runningSum(float y[]) {
    // Replace y[i] with the sum of y[j], 0 <= j <= i
    double sum = y[0];
    for (int i = 1; i < 5; i++) {
        sum += y[i];
        y[i] = sum;
    }
    return sum;
}

int main() {

float x[5] = {10., 20., 30., 40., 50.};
// ...
runningSum(x);

if (x[0] != 10.0 || x[1] != 30. || x[2] != 60. || x[3] != 100. || x[4] != 150.)
  return 1;
return 0; 
}

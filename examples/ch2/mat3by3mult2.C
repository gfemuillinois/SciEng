/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

int main() {

float m[3][3], m1[3][3], m2[3][3];
// Code that initializes m1 and m2 ...
m1[0][0] = 4; 
m1[0][1] = 3; 
m1[0][2] = 2; 
m1[1][0] = 3; 
m1[1][1] = 5; 
m1[1][2] = 2; 
m1[2][0] = 2; 
m1[2][1] = 2; 
m1[2][2] = 1; 
m2[0][0] = -1;
m2[0][1] = -1;
m2[0][2] = 4; 
m2[1][0] = -1;
m2[1][1] = 0; 
m2[1][2] = 2; 
m2[2][0] = 4; 
m2[2][1] = 2; 
m2[2][2] = -11;

// m = m1 * m2
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        double sum = 0.0;
        for (int k = 0; k < 3; k++) {
            sum += m1[i][k] * m2[k][j];
        }
        m[i][j] = sum;
    }
}

for (int i=0; i < 3; i++) {
  if ( m[i][i] != 1 ) return 1;
  for (int j=0; j < 3; j++) {
    if (i != j && m[i][j] != 0) return 1;
  }
}
return 0;
}

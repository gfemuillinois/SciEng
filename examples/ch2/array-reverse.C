/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
int main() {

float x[10];
// ... initialize x ...
for (int j = 0; j < 10; j++) x[j] = j+1;

float* left  = &x[0];
float* right = &x[9];

while (left < right) {
    float temp = *left;

    *left++  = *right;
    *right-- = temp;
}


for (int i = 0; i < 10; i++) {
  if (x[i] != 10-i) return 1;
}
return 0;
}

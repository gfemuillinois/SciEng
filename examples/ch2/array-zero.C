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

float* p = &x[10];
while (p != x) *--p = 0.0;

for (int i = 0; i < 10; i++) {
  if (x[i] != 0) return 1;
}
return 0;
}

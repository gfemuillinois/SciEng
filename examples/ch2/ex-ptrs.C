/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
int main() {

  float x[5];


x[0] = 1.0;
x[4] = 5.0;
*(x+4) = 6.0;
*(&x[3]+1) = 7.0;
/*
*x+4 = 8.0;
(&x)[4] = 9.0;
x[5] = 2.0;
x++; x[4] = 3.0;
*/
int i = x[3] < x[4];
int j = x+3  < x+4;

return 0;
}

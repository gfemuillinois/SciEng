/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
void f() {
int a=1, b=2, c=3;


a = (b = c);   // Assign c to b, then b to a
a = b = c;     // Assign c to b, then b to a




(a = b) = c;  // Assign b to a, then c to a; b is unchanged


}

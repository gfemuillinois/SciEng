/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
int main() {

const float pi = 3.14159;    // Constant object
const float* p = &pi;

/*


*p = 2.0;                    // WRONG


*/


float a;
float* const p1 = &a;




*p1 = 10.0;


/*


float b;
p1 = &b;                     // WRONG


*/


const float e = 2.718281828;
const float* const p2 = &e;


}

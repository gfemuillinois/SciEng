/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
void main() {


extern int f(int&); // Non-const call by reference
#ifdef BAD_COMPILE
f(3);               // WRONG: const actual argument for non-const int& formal argument
#endif



double d;
#ifdef BAD_COMPILE
f(d); // WRONG: temporary required for non-const int& formal argument

#endif
}

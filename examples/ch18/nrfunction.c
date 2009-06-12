/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
/* Fake Numerical Recipes function */

extern "C" void nrerror(const char error_text[]);

extern "C" void nrfunction(void) {
  nrerror("nr: bad stuff happened");
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

extern double log_of(double x, double base);


#include <math.h>
extern double log_of(double x, double base = M_E);// M_E in <math.h>

#ifdef BAD_COMPILE

extern double f(int x = 3, double y);// WRONG: y must have a default argument

#endif

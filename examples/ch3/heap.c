/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <stdlib.h>

void f() {

  float *fp = (float *) malloc(sizeof(float)); /* Allocate a float on the heap. */
  /* ... */
  free(fp); /* Deallocate. */

}
void g() {

  int n;
  float *x;
  scanf("%d", &n);  /* Read count. */
  x = (float *) malloc(n * sizeof(float));
  /* ... */
  free(x);

}

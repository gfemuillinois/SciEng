/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/Boolean.h"
#include <stdlib.h>

#include "not_equal.h"


Boolean operator==(const A& lhs, const A& rhs){
  return Boolean::IsTrue;
}


int main(){
  A a;
  A b;
  if (a != b){
    return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}

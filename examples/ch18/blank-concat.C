/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <string.h>


char* blank_concat(const char* word1, const char* word2) {
    unsigned result_len = strlen(word1) + strlen(word2) + 2;
    char* result = new char[result_len];
    return strcat( strcat( strcpy(result, word1), " " ), word2 );
}


int main() {

  char* p = blank_concat("Hi", "there");
  // ...
  if (strcmp("Hi there", p) != 0) {
     cerr << "Bad concatenation: " << p << endl;
     delete [] p;
     return 1;
   }
  delete [] p;

  return 0;
}

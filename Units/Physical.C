/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Units/Physical.h"

ostream& powerPrinter(ostream& os, int units[7]) {
   static char* letters = "MLTQKIA";
   Boolean saw_positive = Boolean::false;
   Boolean saw_negative = Boolean::false;
   for (int i = 0; i < 7; i++) {
     if (units[i] < 0) saw_negative = Boolean::true;
     if (units[i] > 0) saw_positive = Boolean::true;
   }
   if (saw_negative || saw_positive) os << ' ';

   for (i = 0; i < 7; i++) {
     if (units[i] > 0) {
        os << letters[i];
        if (units[i] > 1) os << '^' << units[i];
      }
   }

   if (!saw_positive && saw_negative) os << "1";

   if (saw_negative) {
      os << '/';
      for (i = 0; i < 7; i++) {
        if (units[i] < 0) os << letters[i];
        if (units[i] < -1) os << '^' << -units[i];
      }
   }
   return os;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <stdlib.h>


void f() {
    float temp = 1.1;
    int a;
    int b;
    cin >> a >> b;

    if (a < b) {
        int temp = a;  // This "temp" hides the one in function scope.
        cout << 2 * temp << endl;
    }// Block ends; local "temp" deleted.
    else {
        int temp = b;  // Another "temp" hides the one in function scope.
        cout << 3 * temp << endl;
    }

    cout << a * b + temp << endl;
}


int main() {
  f();
  f();
  return EXIT_SUCCESS;
}

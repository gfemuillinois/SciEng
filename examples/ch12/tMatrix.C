/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch6/SimpleArray.h"

class Matrix { 
    public:
    // member functions, etc.
}; 




Matrix m;        // We can make objects if Matrix is a class,
Matrix* mp;      // ... and pointers,
Matrix& mr = m;  // ... and references,
Matrix ma[4];    // ... and arrays.




int main() {

SimpleArray<int> a(5);
SimpleArray<int>& r = a;


const SimpleArray<int>& cr = a;

return 0;
}

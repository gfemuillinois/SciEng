/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
int main() {

typedef float distance;


typedef float force;
distance d = 10;
force f;
f = d;

{

// Small machine
typedef short int intNumber;
typedef float floatNumber;

}
{

// Large machine
typedef long int intNumber;
typedef double floatNumber;

}
return 0;
}

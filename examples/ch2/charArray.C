/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

int main() {

char hello1[] = {'H', 'i'};


char hello2[] = "Hi";


char name[15] = "Isaac Newton";


name[12] = '\'';
name[13] = 's';
name[14] = '\0';

std::cout << name << std::endl;
return 0;
}

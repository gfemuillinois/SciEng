/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>


enum Color { red, orange, yellow, green, blue, indigo, violet };


enum Color phosphor_type;


Color c = green;


enum Polygon { triangle = 3, quadrilateral = 4, pentagon = 5 };


int main() {
/*{

enum Color { red, orange, yellow, green, blue, indigo, violet };
enum Crt_colors { red, green, blue };

}*/
  std::cout << (green + triangle) << std::endl;
  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "Units/SIConstants.h"
#include "Units/BritishConstants.h"


class AtwoodsMachine :
    private SIConstants<double> {
public:
    AtwoodsMachine(Mass m1, Mass m2) : the_m1(m1), the_m2(m2) {}
    Acceleration m1Accel() const {
        return g * (the_m2 - the_m1) / (the_m2 + the_m1);
    }
    Force tension() const {
        return g * (2 * the_m1 * the_m2) / (the_m1 + the_m2);
    }
private:
    Mass the_m1;
    Mass the_m2;
};



class DemoAtwoodsMachine :
    private BritishConstants<double> {
public:
    static void demo();
};


void DemoAtwoodsMachine::demo() {

  AtwoodsMachine machine1(1 * kilogram, 2 * kilogram);
  cout << machine1.m1Accel() << " " << machine1.tension() << endl;



  AtwoodsMachine machine2(1 * slug, 2 * slug);
  cout << machine2.m1Accel() << " " << machine2.tension() << endl;


  cout << machine2.m1Accel().convertTo(ft_per_sec2) << " "
    << machine2.tension().convertTo(pound) << endl;

}

int main() {
  DemoAtwoodsMachine::demo();
  return 0;
}

/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "SciEng/SciEngErr.h"
#include "SciEng/String.h"

using std::cout;
using std::cin;
using std::endl;

class NumericalRecipesErr :
    public SciEngErr {
public:
    NumericalRecipesErr(const String& msg);
    virtual String message() const;
private:
    String the_msg;
};

extern "C" void nrerror(char error_text[]) {
    throw NumericalRecipesErr(error_text);
}


NumericalRecipesErr::NumericalRecipesErr(const String& msg) : the_msg(msg) {}

String NumericalRecipesErr::message() const { return the_msg; }

extern "C" void nrfunction();

int main() {

  try {
    nrfunction(); // Function in Numerical Recipes
    // ...
  } catch (const SciEngErr& e) {
    cout << e.message() << endl;
  }

  return 0;
}

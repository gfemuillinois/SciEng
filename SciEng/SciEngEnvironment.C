/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/SciEngEnvironment.h"

#include <iostream>

using std::cerr;
using std::endl;
using std::cout;

//namespace SciEngLib{

void userErrMessage(const SciEngErr& e) {     
    cerr << endl 
	 << "*** \"Scientific and Engineering C++\" -- error detected." 
	 << endl;
    cerr << e;
    cerr << endl << "*** End of error message ***" << endl;
}



String FinalErr::message() const {
    return "FinalErr: probably no catch for a throw.";
}


// Allocate "out of memory" message before running out of memory
String OutOfMemoryErr::out_of_memory_message("C++ new was unable to allocate memory.");

String OutOfMemoryErr::message() const {
    return out_of_memory_message;
}



NewHandler SciEngStartup::nh;           // These handlers are initialized ...
Terminate  SciEngStartup::th;
SciEngStartup::SciEngStartup() { // ... before this constructor is first called.

  cout << "SciEngStartup::SciEngStartup() called " << endl;
}       

//}

#ifndef ERRORH
#define ERRORH

#include <iostream>
#include <string>


void errLoc( const int line, const std::string &file, 
	     std::ostream &out =std::cerr);

void errStop( const std::string &message, std::ostream &out = std::cerr);

// *******************************************************************
// *******************************************************************


#define ERREXIT(str)  do{errLoc(__LINE__,__FILE__);errStop(str);}while(0)

#define ERRCHK(ex,str)   do { if(ex) { errLoc(__LINE__,__FILE__); \
                                       errStop(str);   }  } while(0)

// *******************************************************************
// *******************************************************************

#endif

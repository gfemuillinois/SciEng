
#include <cstdio>
#include <cstdlib>
#include "error.h"

using std::endl;

void errLoc( const int line, const std::string &file, std::ostream &out ) {

  out << "In line " << line << " of file " << file << ": ";
}
// *******************************************************************
// *******************************************************************

void errStop( const std::string &message, std::ostream &out ) {

  out << message << endl;
  exit(EXIT_FAILURE);
}
// *******************************************************************
// *******************************************************************

bool boost_error(char const * expr, char const * func, char const * file, 
		 long line)
{
  std::printf("%s(%ld): Assertion '%s' failed in function '%s'\n", file, 
	      line, expr, func);
  return true; // fail w/ standard assert()
}
// *******************************************************************
// *******************************************************************

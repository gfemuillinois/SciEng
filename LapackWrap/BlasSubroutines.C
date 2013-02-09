/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "LapackWrap/BlasSubroutines.h"
#include "SciEng/SciEngString.h"
#include "SciEng/clarch.h"

char Blas2Subroutines::trans_char[] = {'N','T'};
char Blas3Subroutines::trans_char[] = {'N','T','C'};



String BlasErr::message() const { 

    String s =
              "XERBLA from BLAS/LAPACK reports that " +
              the_subr_name +
              " has an illegal value in argument number ";
    return s << the_arg_num;

}

extern "C"
void FTNAME(xerbla)( const char subr_name[6], int& arg_num){ 

  //  cout << "FTNAME(xerbla) called " << endl;

    throw BlasErr(String(subr_name, 6), arg_num);
}


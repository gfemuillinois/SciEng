/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/SciEngString.h"
#include "LapackWrap/LapackErr.h"

String LapackErr::InvalidFactoredMatrixUse::message() const {
  return "Invalid use of factored matrix.";
}

String LapackErr::ErrorWithInfo::message() const {
  String s;
  s << "LAPACK subroutine failed with info = " << info_val << ".";
  return s;
}

String LapackErr::UnableToFactor::message() const {
  String s;
  s << "LAPACK(xGETRF) is unable to factor matrix; info = " << info_val << "; ";
  if (info_val < 0) {
    s << "argument " << -info_val << " has illegal value!";
  } else {
    s << "matrix is singular, U(" << info_val-1 << "," << info_val-1 << ") is exactly zero";
  }
  return s;
}

String LapackErr::UnableToFactorSVD::message() const {
  String s;
  s << "LAPACK(xGESVD) is unable to factor matrix; info = " << info_val << "; ";
  if (info_val < 0) {
    s << "argument " << -info_val << " has illegal value!";
  } else {
    s << "info off-diagonal elements of an intermediate bidiagonal form did not converge to zero;\n";
    //   s << endl;
    s << "Likely cause: Infinite (NaNQ, INF) numbers in SVD input.";
  }
  return s;
}

String LapackErr::UnableToSolve::message() const {
  String s;
  s << "LAPACK(xGETRS) is unable to solve matrix; info = " << info_val << ".";
  return s;
}

String LapackErr::NotPositiveDefinite::message() const {
  String s;
  s << "LAPACK(xPxETRF) finds not positive definite matrix; info = " << info_val << ".";
  return s;
}

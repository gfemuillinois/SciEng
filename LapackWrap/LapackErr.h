/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LapackErrH
#define LapackErrH

#include "SciEng/SciEngErr.h"

class LapackErr {
public:
  class InvalidFactoredMatrixUse : public SciEngErr {
  public:
    virtual String message() const;
  };
  
  class ErrorWithInfo : public SciEngErr {
  public:
    ErrorWithInfo(int info) : info_val(info) {}
    virtual String message() const;
  protected:
    const int info_val;   // Information returned by LAPACK
  };

  class UnableToFactor : public ErrorWithInfo {
  public:
    UnableToFactor(int info) : ErrorWithInfo(info) {}
    virtual String message() const;
  };

  class UnableToFactorSVD : public ErrorWithInfo {
  public:
    UnableToFactorSVD(int info) : ErrorWithInfo(info) {}
    virtual String message() const;
  };
  
  class UnableToSolve : public ErrorWithInfo {
  public:
    UnableToSolve(int info) : ErrorWithInfo(info) {}
    virtual String message() const;
  };
 
  class NotPositiveDefinite : public ErrorWithInfo {
  public:
    NotPositiveDefinite(int info) : ErrorWithInfo(info) {}
    virtual String message() const;
  };
};

#endif

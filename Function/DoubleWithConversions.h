/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DoubleH
#define DoubleH

class Double {
public:
  Double(double d) : the_double(d) {}
  Double() : the_double(0.0) {}
  operator double&(){return the_double;}
  operator const double&() const {return the_double;}
private:
  double the_double;
};
      
#endif


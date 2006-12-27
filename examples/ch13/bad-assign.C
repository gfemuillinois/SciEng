/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
class ConstArray2d {
  // Dummy interface base
public:
  virtual void foo() = 0;

  virtual ~ConstArray2d();
};


void f(ConstArray2d<int>& a, ConstArray2d<int>& b) {
    a = b;
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <strstream.h>
#include "examples/ch4/SimpleArray.h"
#include "SciEng/Boolean.h"

#include "examples/ch6/Interval.h"

template<class T>
class Fallible {
public:

    Fallible(const T& t)  : is_valid(Boolean::IsTrue), instance(t) {}     // Valid.
    Fallible()            : is_valid(Boolean::IsFalse)             {}     // Invalid.


    Boolean failed()  const { return !is_valid;          }   // True if invalid.
    Boolean valid()   const { return is_valid;           }   // True if valid.
    void invalidate()       { is_valid = Boolean::IsFalse; }   // Make invalid.
    operator T()      const;

    T elseDefaultTo(const T& default_value) const; // Value if valid, else default_value

    class UsedInInvalidStateErr {
        // ...
    };
private:
    Boolean is_valid;
    T instance;
};



template<class T>
inline 
Fallible<T>::operator T() const {
    if (failed()) throw UsedInInvalidStateErr();
    return instance;
}


template<class T>
inline T Fallible<T>::elseDefaultTo(const T& default_value) const {
  return valid() ? instance : default_value;
}





extern ostream& operator<<(ostream& os, const Interval& i);


extern istream& operator>>(istream& is, Interval& i);


class SetOfIntervals {
public:

    SetOfIntervals(int max_number_of_intervals);
    void add(Interval);                                  // Add interval to set
    Fallible<Interval> intervalContaining(double val);   // Find interval containing val

private:
    int num_intervals;
    SimpleArray<Interval> intervals;
};


int main() {

  SetOfIntervals s(5);
  s.add(Interval(-100, -50));
  s.add(Interval(-1, 1));
  s.add(Interval(2, 4));
  // ...

  Interval interval_about_0 = s.intervalContaining(0);
  try {
  Interval interval_about_5 = s.intervalContaining(5);  // Exception thrown

  return 1;
  } catch(...) {}

  if ( s.intervalContaining(11.2).valid() ) {
    // ...
  }


  Interval HugeInterval(-1.0e10, 1.0e10);
  Interval interval_about_10 = s.intervalContaining(10).elseDefaultTo(HugeInterval);

  cout << interval_about_0 << endl;
  cout << interval_about_10 << endl;


  Interval small(-.01, .02);
  // ...
  cout << small << endl;


  istrstream in("[1,2] [3,,4]");
  Interval i;
  in >> i;
  if (i.lo() != 1 || i.hi() != 2) return 1;
  in >> i;
  if (in || i.lo() != 1 || i.hi() != 2) return 1;
  return 0;
}

void SetOfIntervals::add(Interval i) { intervals[num_intervals++] = i; }
SetOfIntervals::SetOfIntervals(int max_number_of_intervals) : num_intervals(0), intervals(max_number_of_intervals) {}


Fallible<Interval> SetOfIntervals::intervalContaining(double val) {
    for (int i = 0; i < num_intervals; i++) {
        Interval& t = intervals[i];
        if (t.lo() <= val && val <= t.hi()) return t; // Valid state
    }
    return Fallible<Interval>(); // Invalid state
}


Interval::Interval() {}
Interval::Interval(double lo, double hi) : the_lo(lo), the_hi(hi) {}
double Interval::lo() const { return the_lo; }
double Interval::hi() const { return the_hi; }


ostream& operator<<(ostream& os, const Interval& i) { 
    return os << '[' << i.lo() << ", " << i.hi() << ']';
}



istream& operator>>(istream& is, Interval& i) {
    char lbracket = 0;
    char rbracket = 0;
    char comma = 0;
    double lo;
    double hi;
    is >> lbracket >> lo >> comma >> hi >> rbracket;
    if (lbracket != '[' || comma != ',' || rbracket != ']') is.clear(ios::badbit);
    else if (is) i = Interval(lo, hi);
    return is;
}


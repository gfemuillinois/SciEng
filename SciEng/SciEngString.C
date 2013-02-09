/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <iomanip>
#include <ctype.h>
//#include <sstream>  // iso C++
//#include <strstream> // old C++
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "SciEng/SciEngString.h"

//namespace SciEngLib{

String::String() :
    data(new char[1]) {
    data[0] = 0;
}


String::String(const char* s) : 
    data( strcpy(new char[::strlen(s) + 1], s) ) {
}

String::String(char c) :
    data(new char[2]) {
    data[0] = c;
    data[1] = '\0'; // Null terminate
}


String::String(const char* s, Subscript n) :
    data( strncpy(new char[n + 1], s, n) ) {
    data[n] = '\0';  // Null terminate
}

String::String(const String& s) :
  data( strcpy(new char[s.strlen() + 1], s.data) ) {
}


String& String::operator=(const String& rhs) {
    if (data != rhs.data) {
        delete [] data;
        data = strcpy(new char[rhs.strlen() + 1], rhs.data);
    }
    return *this;
}


String& String::operator=(const char* rhs) {
    if (data != rhs) {
        delete [] data;
        data = strcpy(new char[::strlen(rhs) + 1], rhs);
    }
    return *this;
}
 
String& String::operator=(char rhs) {
    delete [] data;
    data = new char[2];
    data[0] = rhs;
    data[1] = '\0';
    return *this;
}
    

String& String::operator+=(const String& rhs) { 
    char* new_data = 
        strcat(strcpy(new char[this->strlen() + rhs.strlen() + 1], data), rhs.data);
    delete [] data;
    data = new_data;
    return *this;
}



String::String(const String& s1, const String& s2) :
    data( strcat(strcpy(new char[s1.strlen() + s2.strlen() + 1], s1.data), s2.data) ) {
}

String operator+(const String& lhs, const String& rhs) {
    return String(lhs, rhs);
}



  Boolean operator==(const String& lhs, const String& rhs) {
    return strcmp(lhs.data, rhs.data) == 0;
  }
  Boolean operator<(const String& lhs, const String& rhs) {
    return strcmp(lhs.data, rhs.data) < 0;
  }
  // ...

  Boolean operator!=(const String& lhs, const String& rhs) {
    return strcmp(lhs.data, rhs.data) != 0;
  }
  Boolean operator<=(const String& lhs, const String& rhs) {
    return strcmp(lhs.data, rhs.data) <= 0;
  }
  Boolean operator>(const String& lhs, const String& rhs) {
    return strcmp(lhs.data, rhs.data) > 0;
  }
  Boolean operator>=(const String& lhs, const String& rhs) {
    return strcmp(lhs.data, rhs.data) >= 0;
  }

String::~String() { delete [] data; }


Fallible<Subscript> String::find(char find_me) const {

    const char* foundp = strchr(data, find_me);
    if (foundp) return Fallible<Subscript>(foundp - data);
    else        return Fallible<Subscript>();

}


Fallible<Subscript> String::findlast(char find_me) const {

    const char* foundp = strrchr(data, find_me);
    if (foundp) return Fallible<Subscript>(foundp - data);
    else        return Fallible<Subscript>();

}

Fallible<Subscript> String::find(const String& find_me) const {

    const char*foundp = strstr(data, find_me.data);
    if (foundp)return Fallible<Subscript>(foundp - data);
    else       return Fallible<Subscript>();

}

Fallible<Subscript> String::brk(const String& any_of_me) const {

    const char*foundp = strpbrk(data, any_of_me.data);
    if (foundp)return Fallible<Subscript>(foundp - data);
    else       return Fallible<Subscript>();

}

Subscript String::span(const String& consisting_of_me) const {
    return strspn(data, consisting_of_me.data);
}

Subscript String::cspan(const String& consisting_not_of_me) const {
    return strcspn(data, consisting_not_of_me.data);
}

std::ostream& operator<<(std::ostream& s, const String& cs) {
    return s << cs.data;
}



std::istream& operator>>(std::istream& s, String& cs) {
    const int bufsize = 100;
    char buf[bufsize];
    cs = String();
    while ( s >> std::setw(bufsize) >> buf ) {
        cs += buf;
        int next_input_char = s.peek();
        if (isspace(next_input_char)) {
            // Read terminated by white space, not lack of room --> stop reading
            break;
        }
    }
    return s;
}


String String::subString(Subscript start) const {
  Subscript strt =  (start <= strlen()) ? start : strlen();  // null if too far from beginning
  return String(data + strt);
}

String String::subString(Subscript start, Subscript run_len) const {
  Subscript strt =  (start < strlen()) ? start : strlen();  // null if too far from beginning
  Subscript rn = ( start + run_len <= strlen() ) ? run_len : strlen();
  return String(data + strt, rn  );
}

String& operator<<(String& s, const char* p) {
  // Write a C string into a String.  This is a specialization
  // of the operator<<(String, const T&) template function that bypasses
  // using ostrstream.
  return s += String(p);
}


Fallible<double> String::strtod() const {
    errno = 0; // Clear error indication
    char* endp;
    double result = ::strtod(data, &endp);

    if (errno || *endp) return Fallible<double>();
    else                return Fallible<double>(result);

}


Fallible<long> String::strtol() const {
  errno = 0;  // Clear error indication
  char* endp;
  long result = ::strtol(data, &endp, 0);
  if (errno || *endp) return Fallible<long>();
  else             return Fallible<long>(result);
}


Fallible<unsigned long> String::strtoul() const {
  errno = 0;  // Clear error indication
  char* endp;
  unsigned long result = ::strtoul(data, &endp, 0);
  if (errno || *endp) return Fallible<unsigned long>();
  else             return Fallible<unsigned long>(result);
}

//}

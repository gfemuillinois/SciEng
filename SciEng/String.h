/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef StringH
#define StringH

#include <cstring>
#include "SciEng/Subscript.h"
#include "SciEng/Fallible.h"

#include <iosfwd>

//namespace SciEngLib{

class String {
public:

    // Constructors
    String();                           // Null string
    String(const char*);                // From built-in string
    String(const char*, Subscript n);   // ... for at most n characters
    String(char);              // From single character
    String(const String&);              // From another String

    // Assignment
    String& operator=(const String&);   // Assign from String
    String& operator=(const char*);     // ... from built-in string
    String& operator=(char);            // ... from single character


    // Destructor
    ~String();

    // Indexing

    char  operator[](Subscript i) const;
    char& operator[](Subscript i);
    char  operator()(Subscript i) const;
    char& operator()(Subscript i);


    // Concatenation
    String& operator+=(const String& rhs);
    friend String operator+(const String& lhs, const String& rhs);


    // Comparisons

    friend Boolean operator==(const String&, const String&);
    friend Boolean operator!=(const String&, const String&);
    friend Boolean operator< (const String&, const String&);
    friend Boolean operator<=(const String&, const String&);
    friend Boolean operator> (const String&, const String&);
    friend Boolean operator>=(const String&, const String&);



    // Searches

    Fallible<Subscript> find(const String& s)   const;  // First occurence of s
    Fallible<Subscript> find(char c)            const;  // First occurence of c
    Fallible<Subscript> findlast(char c)        const;  // Last occurence of c
    Fallible<Subscript> brk(const String& s)    const;  // First occurence of any character in s
    Subscript           span(const String& s)   const;  // Size of initial span of characters in s
    Subscript           cspan(const String& s)  const;  // Size of initial span of characters not in s



    // Sub-strings

    String subString(Subscript start             ) const;  // From start 
    String subString(Subscript start, Subscript n) const;  // ... for n characters


    // Miscellaneous

    Subscript   strlen() const;  // Length of string (not including null)
    const char* c_str()  const;  // Pointer to underlying built-in string
    char*       c_str();         // Pointer to underlying built-in string


    // Conversion into numbers

    Fallible<double>        strtod()  const;    // Conversion to double
    Fallible<long>          strtol()  const;    // Conversion to long
    Fallible<unsigned long> strtoul() const;    // Conversion to unsigned long


    // I/O

    friend std::ostream& operator<<(std::ostream& s, const String& cs);
    friend std::istream& operator>>(std::istream& s, String& cs);



    // Iterators
    class Iterator; // Forward declaration

    class Browser {
    public:
        Browser(const String& s);


        Boolean more() const;
        void    advance();
        char    current() const;


        Browser(const Iterator&);
    private:
        const char* cur;
        const char* endp;
    };

    class Iterator {
    public:
        Iterator(String& s);


        Boolean more() const;
        void    advance();
        char&   current() const;

    private:
        friend Browser::Browser(const Iterator&);
        char* cur;
        const char* endp;
    };

private:
    char* data; // Pointer to built-in character string

    String(const String&, const String&);
};



inline const char* String::c_str() const { 
    return data; 
}
inline char* String::c_str() {
    return data;
}


inline char String::operator[](Subscript i) const { return data[i]; }
inline char& String::operator[](Subscript i) { return data[i]; }
inline char String::operator()(Subscript i) const { return data[i]; }
inline char& String::operator()(Subscript i) { return data[i]; }

inline Subscript String::strlen() const { return ::strlen(data); }


inline String::Browser::Browser(const String& s) : cur(s.c_str()), endp(cur + s.strlen()) {}
inline Boolean String::Browser::more() const { return cur < endp; }
inline void    String::Browser::advance()    { ++cur; }
inline char    String::Browser::current() const { return *cur; }

inline String::Iterator::Iterator(String& s) : cur(s.c_str()), endp(cur + s.strlen()) {}
inline Boolean String::Iterator::more() const { return cur < endp; }
inline void    String::Iterator::advance()    { ++cur; }
inline char& String::Iterator::current() const { return *cur; }

inline String::Browser::Browser(const String::Iterator& iter) : cur(iter.cur), endp(iter.endp) {}


template<class T>
String& operator<<(String& s, const T& obj); // Format into string object


// Declare commonly used cases of << to avoid proliferation of functions
String& operator<<(String&, const char*);  // Special case

// CAD: These guys are not defined anywhere so the compiler must
// expand the template. When we declare these guys, g++ does not
// expand the template and the loader complains about undefined 
// function!

String& operator<<(String&, const char&);
//String& operator<<(String&, const int&);
String& operator<<(String&, const unsigned int&);
String& operator<<(String&, const long int&);
String& operator<<(String&, const unsigned long int&);
String& operator<<(String&, const float&);
String& operator<<(String&, const double&);

//}

#ifdef XLC_QNOTEMPINC
#include "SciEng/String.cxx"
#endif

#endif


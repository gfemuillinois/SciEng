/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <ctype.h>
#include "SciEng/Boolean.h"
#include "SciEng/String.h"


class Lexer {
public:
    Lexer(const String& s);

    enum TokenKind { open, close, number, x, word, comma };

    TokenKind current() const;
    void advance();
    Boolean more() const;


    String name() const;    // Name of a word
    double value() const;   // Value of a number


    // ...
    private:
    String input;
    Subscript cur;
    Subscript leng;
    TokenKind kind;

    void skipWhiteSpace();
};


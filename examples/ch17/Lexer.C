/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch17/Lexer.h"

Lexer::Lexer(const String& s) : input(s), cur(0), leng(0) { advance(); }

Boolean Lexer::more() const { return cur + leng <= input.strlen(); }
void Lexer::advance() {
  cur += leng;
  skipWhiteSpace();
  char c = input[cur];
  if (c == '(') { kind = open; leng = 1; }
  else if (c == ')') { kind = close; leng = 1; }
  else if (c == ',') { kind = comma; leng = 1; }
  else if (c == 'x' && !isalnum(input[cur+1])) { kind = x; leng = 1; }
  else if (isalpha(c)) {
    kind = word;
    for (leng = 1; isalnum(input[cur+leng]); leng++);
  }
  else {
    kind = number;
    for (leng = 1; isdigit(input[cur+leng]); leng++);  // Digits
    if (input[cur+leng] == '.') leng++;    // Decimal point
    for (; isdigit(input[cur+leng]); leng++);  // Digits
    if (input[cur+leng] == 'e' || input[cur+leng] == 'E') {
      leng++;
      if (input[cur+leng] == '+' || input[cur+leng] == '-') leng++;
      for (; isdigit(input[cur+leng]); leng++);  // Digits
    }
  }
}

Lexer::TokenKind Lexer::current() const { return kind; }

double Lexer::value() const {
  return input.subString(cur, leng).strtod();
}

String Lexer::name() const {
  return input.subString(cur, leng);
}

void Lexer::skipWhiteSpace() {
  while (isspace(input[cur])) cur++;
}

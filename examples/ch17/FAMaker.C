/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch17/FAMaker.h"


FAMaker::FAMaker(const String& input) : 
    function_names(7),   // Increase size for each new function.
    functions(7),
    lexer(input) {

    function_names(0) = "exp";        functions(0) = exp;
    function_names(1) = "add";        functions(1) = add;
    function_names(2) = "subtract";   functions(2) = subtract;
    function_names(3) = "multiply";   functions(3) = multiply;
    function_names(4) = "divide";     functions(4) = divide;
    function_names(5) = "sin";        functions(5) = sin;
    function_names(6) = "cos";        functions(6) = cos;

    // Add new function name and load member function pointer here.
}



FunctionalAlgebra<double> FAMaker::function() {  
    if (lexer.more() && lexer.current() == Lexer::word) {
        ParserFunction f = lookup(lexer.name());
        lexer.advance();
        if (lexer.more() && lexer.current() == Lexer::open) {
            lexer.advance();
            FunctionalAlgebra<double> alg = (this->*f)();
            if (lexer.current() == Lexer::close) {
                lexer.advance();
                return alg;
            }
        }
    }
    throw SyntaxErr();
}

          

FunctionalAlgebra<double> FAMaker::term() {
    if (lexer.more()) {
        if (lexer.current() == Lexer::number) {
            double val = lexer.value();
            lexer.advance();
            return  new ConstantFunctional<double>(val);
        }
        else if (lexer.current() == Lexer::x) {
            lexer.advance();
            return new XFunctional<double>();
        }
        else if (lexer.current() == Lexer::word) return function();
    }
    throw SyntaxErr();
}


          

FAMaker::ParserFunction FAMaker::lookup(const String& function_name) const { 
    for (Subscript i = 0; i < function_names.numElts(); i++) { 
        if (function_names(i) == function_name) return functions(i);
    }
    throw FunctionUndefined(function_name);
}



FunctionalAlgebra<double> FAMaker::exp() { 
    return ::exp(term());
}

FunctionalAlgebra<double> FAMaker::add() {
    FunctionalAlgebra<double> lhs = term();
    skipComma();
    FunctionalAlgebra<double> rhs = term();
    return lhs+rhs;
}


FunctionalAlgebra<double> FAMaker::sin() {
  return ::sin(term());
}

FunctionalAlgebra<double> FAMaker::cos() {
  return ::cos(term());
}

FunctionalAlgebra<double> FAMaker::subtract() {
  FunctionalAlgebra<double> lhs = term();
  skipComma();
  FunctionalAlgebra<double> rhs = term();
  return lhs-rhs;
}

FunctionalAlgebra<double> FAMaker::multiply() {
  FunctionalAlgebra<double> lhs = term();
  skipComma();
  FunctionalAlgebra<double> rhs = term();
  return lhs*rhs;
}

FunctionalAlgebra<double> FAMaker::divide() {
  FunctionalAlgebra<double> lhs = term();
  skipComma();
  FunctionalAlgebra<double> rhs = term();
  return lhs/rhs;
}

String FAMaker::SyntaxErr::message() const {
  return "Syntax error";
}

String FAMaker::FunctionUndefined::message() const {
  return "This function is not defined in FAMaker:" + the_name;
}


void FAMaker::skipComma() {
    if (lexer.more() && lexer.current() == Lexer::comma) {
        lexer.advance();
        return;
    }
    throw SyntaxErr();
}


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FAMakerH
#define FAMakerH
#include "Function/FunctionalAlgebra.h"
#include "Array/ConcreteFormedArray1d.h"
#include "examples/ch17/Lexer.h"


class FAMaker {  
public:
    FAMaker(const String& input);
    FunctionalAlgebra<double> function();
    FunctionalAlgebra<double> term();

    FunctionalAlgebra<double> exp();
    FunctionalAlgebra<double> add();
    FunctionalAlgebra<double> subtract();
    FunctionalAlgebra<double> multiply();
    FunctionalAlgebra<double> divide();
    FunctionalAlgebra<double> cos();
    FunctionalAlgebra<double> sin();
    // Add functions here and in constructor.

    // ... Exception classes SyntaxErr and FunctionUndefined ...
    class SyntaxErr :
    public SciEngErr {
    public:
    virtual String message() const;
    };

    class FunctionUndefined :   
    public SciEngErr {
    public:
    FunctionUndefined(const String& name) : the_name(name) {}
    virtual String message() const;
    private:
    String the_name;
    };
private:
    Lexer lexer;

    typedef FunctionalAlgebra<double> (FAMaker::*ParserFunction)();
    ConcreteFormedArray1d<String> function_names;
    ConcreteFormedArray1d<ParserFunction> functions;
    ParserFunction lookup(const String& function_name) const;

    void skipComma();
};


#endif

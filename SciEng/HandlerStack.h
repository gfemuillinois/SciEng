/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef HandlerStackH
#define HandlerStackH


typedef void (*HandlerFunction)();
typedef HandlerFunction (*HandlerFunctionSetter)(HandlerFunction);

template<HandlerFunctionSetter set_function>
class HandlerStack {
public:

    HandlerStack();                   // Establish default handler
    HandlerStack(HandlerFunction);    // Establish specified handler
    ~HandlerStack();                  // Re-establish previous handler
    static void defaultHandler();     // Default handler to establish
private:
    const HandlerFunction old_handler;// Pointer to previous new handler

};


#ifdef XLC_QNOTEMPINC
#include "SciEng/HandlerStack.c"
#endif

#endif


/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

//namespace SciEngLib{

template<HandlerFunctionSetter set_function>
HandlerStack<set_function>::HandlerStack(HandlerFunction new_handler) :
    old_handler( set_function(new_handler) ) {
}

template<HandlerFunctionSetter set_function>
HandlerStack<set_function>::HandlerStack() :
    old_handler( set_function(defaultHandler) ) {
}

template<HandlerFunctionSetter set_function>
HandlerStack<set_function>::~HandlerStack() {
    set_function(old_handler);
}

//}

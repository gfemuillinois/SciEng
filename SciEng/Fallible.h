/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FallibleH
#define FallibleH

#include "SciEng/Boolean.h"
#include "SciEng/SciEngErr.h"


class FallibleBase {
public:
    FallibleBase(Boolean state) : is_valid(state) {}

    Boolean failed() const { return !is_valid;          }   // True if invalid.
    Boolean valid()  const { return is_valid;           }   // True if valid.
    void invalidate()      { is_valid = Boolean::false; }   // Make invalid.


    class UsedInInvalidStateErr : 
        public SciEngErr {
    public:
        virtual String message() const;
    };
protected:
    void throwErr() const;
private:
    Boolean is_valid;
};



template<class T>
class Fallible : 
    private FallibleBase {
public:

    Fallible(const T& t) : FallibleBase(Boolean::true), instance(t) {}   // Valid.
    Fallible()           : FallibleBase(Boolean::false)             {}   // Invalid.

    FallibleBase::failed;
    FallibleBase::valid;
    FallibleBase::invalidate;

    operator T() const;

    T elseDefaultTo(const T& default_value) const; // Value if valid, else default_value
private:
    T instance;
};

template<class T>
inline 
Fallible<T>::operator T() const {
    if (failed()) throwErr();
    return instance;
}

template<class T>
inline 
T Fallible<T>::elseDefaultTo(const T& default_value) const {
    return valid() ? instance : default_value;
}

#endif

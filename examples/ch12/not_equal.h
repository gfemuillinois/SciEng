
#ifndef NOTEQUALH
#define NOTEQUALH

#include "SciEng/Boolean.h"

template<class T>
Boolean operator!=(const T& lhs, const T& rhs){ 
    return ! (lhs == rhs);
}


class A {
public:
  friend Boolean operator==(const A& lhs, const A& rhs);
};

#endif
